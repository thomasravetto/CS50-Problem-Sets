import os

from cs50 import SQL
from flask import Flask, flash, redirect, render_template, request, session
from flask_session import Session
from tempfile import mkdtemp
from werkzeug.security import check_password_hash, generate_password_hash
from datetime import datetime

from helpers import apology, login_required, lookup, usd, check_password

# Configure application
app = Flask(__name__)

# Ensure templates are auto-reloaded
app.config["TEMPLATES_AUTO_RELOAD"] = True

# Custom filter
app.jinja_env.filters["usd"] = usd

# Configure session to use filesystem (instead of signed cookies)
app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"
Session(app)

# Configure CS50 Library to use SQLite database
db = SQL("sqlite:///finance.db")

# Make sure API key is set
if not os.environ.get("API_KEY"):
    raise RuntimeError("API_KEY not set")


@app.after_request
def after_request(response):
    """Ensure responses aren't cached"""
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response


@app.route("/")
@login_required
def index():
    """Show portfolio of stocks"""
    id = session["user_id"]

    # Querying data from database
    stocks_db = db.execute(
        "SELECT name, symbol, price, SUM(quantity) AS shares FROM transactions WHERE username = ? GROUP BY symbol HAVING SUM(quantity) > 0", id)

    # Querying database for user's balance
    balance = db.execute("SELECT cash FROM users WHERE id = ?", id)

    # Calculating total balance
    total_shares_value = 0

    for row in stocks_db:
        total_shares_value += (row["price"] * row["shares"])

    total_balance = total_shares_value + balance[0]["cash"]

    # Displaying the index template
    return render_template("index.html", stocks=stocks_db, cash=balance[0]["cash"], total_cash=total_balance)


@app.route("/buy", methods=["GET", "POST"])
@login_required
def buy():
    """Buy shares of stock"""
    # If user uses post method
    id = session["user_id"]
    if request.method == "POST":

        # Getting all values from inputs
        symbol = request.form.get("symbol")
        stock = lookup(symbol)
        cash = db.execute("SELECT cash FROM users WHERE id = ?", id)

        if not symbol:
            return apology("Symbol missing", 400)

        # Validating stock symbol
        if stock == None:
            return apology("Invalid symbol", 400)

        # Validating stock number
        if not request.form.get("shares"):
            return apology("Missing shares")

        try:
            shares = int(request.form.get("shares"))
        except ValueError:
            return apology("Invalid shares input")

        if shares <= 0:
            return apology("Invalid number of shares", 400)

        # Creating other variables to pass to other functions

        # Making sure the user has enough money to complete the operation
        if (int(cash[0]["cash"]) - (stock["price"] * shares)) <= 0:
            return apology("not enough cash")

        # Inserting transaction data inside "transactions" database
        db.execute("INSERT INTO transactions VALUES (?, ?, ?, ?, ?, ?)", id,
                   stock["name"], stock["symbol"], stock["price"], shares, str(datetime.now()))

        # Updating user's cash
        new_balance = cash[0]["cash"] - (stock["price"] * shares)
        db.execute("UPDATE users SET cash = ? WHERE id = ?", new_balance, session["user_id"])

        flash("Bought!")

        # Rendering the template
        return redirect("/")

    # If user uses a get method
    return render_template("buy.html")


@app.route("/history")
@login_required
def history():
    """Show history of transactions"""
    # Querying the database for all the transactions data
    transactions_db = db.execute("SELECT * FROM transactions WHERE username = ? ORDER BY time", session["user_id"])

    return render_template("history.html", transactions=transactions_db)


@app.route("/login", methods=["GET", "POST"])
def login():
    """Log user in"""

    # Forget any user_id
    session.clear()

    # User reached route via POST (as by submitting a form via POST)
    if request.method == "POST":

        # Ensure username was submitted
        if not request.form.get("username"):
            return apology("must provide username", 403)

        # Ensure password was submitted
        elif not request.form.get("password"):
            return apology("must provide password", 403)

        # Query database for username
        rows = db.execute("SELECT * FROM users WHERE username = ?", request.form.get("username"))

        # Ensure username exists and password is correct
        if len(rows) != 1 or not check_password_hash(rows[0]["hash"], request.form.get("password")):
            return apology("invalid username and/or password", 403)

        # Remember which user has logged in
        session["user_id"] = rows[0]["id"]

        # Redirect user to home page
        return redirect("/buy")

    # User reached route via GET (as by clicking a link or via redirect)
    else:
        return render_template("login.html")


@app.route("/logout")
def logout():
    """Log user out"""

    # Forget any user_id
    session.clear()

    # Redirect user to login form
    return redirect("/")


@app.route("/quote", methods=["GET", "POST"])
@login_required
def quote():
    """Get stock quote."""
    # If user uses post mehod
    if request.method == "POST":

        # Assigning input value to a variable
        symbol = request.form.get("symbol")

        # Passing symbol into lookup function
        stock = lookup(symbol)

        # Checking if symbol is valid
        if stock == None:
            return apology("invalid symbol")

        # Returning values to render_template
        return render_template("quoted.html", stock=stock)

    # If user uses a get method
    return render_template("quote.html")


@app.route("/register", methods=["GET", "POST"])
def register():
    """Register user"""
    # If user uses post method
    if request.method == "POST":

        # Assigning input values to variables
        username = request.form.get("username")
        password = request.form.get("password")
        confirmation = request.form.get("confirmation")

        # Getting username from users database
        rows = db.execute("SELECT username FROM users WHERE username = ?", username)

        # Checking if the input values are correct
        if not username:
            return apology("MISSING USERNAME")

        if not password:
            return apology("MISSING PASSWORD")

        if not confirmation:
            return apology("MISSING CONFIRMATION")

        if not check_password(password):
            return apology("Password must be at least 8 characters long, and must contain at least one lowercase, one uppercase and one special character")

        if password != confirmation:
            return apology("CONFIRMATION DOES NOT CORRESPOND TO PASSWORD")

        if len(rows) != 0:
            return apology("USERNAME ALREADY EXISTS")

        else:
            # Inserting username data into users database
            db.execute("INSERT INTO users (username, hash) VALUES (?, ?)", username, generate_password_hash(password))
            return redirect("/quote")

    # If user uses get method
    return render_template("register.html")


@app.route("/sell", methods=["GET", "POST"])
@login_required
def sell():
    """Sell shares of stock"""
    id = session["user_id"]

    if request.method == "GET":
        user_symbols = db.execute("SELECT symbol FROM transactions WHERE username = ? GROUP BY symbol HAVING SUM(quantity) > 0", id)

        return render_template("sell.html", symbols=[row["symbol"] for row in user_symbols])

    else:
        symbol = request.form.get("symbol")
        shares = int(request.form.get("shares"))

        rows = db.execute("SELECT quantity FROM transactions WHERE username = ? AND symbol = ? GROUP BY symbol", id, symbol)
        user_shares = rows[0]["quantity"]

        stock = lookup(symbol)

        db_user_cash = db.execute("SELECT cash FROM users WHERE id = ?", id)
        user_cash = db_user_cash[0]["cash"]

        transaction_value = shares * stock["price"]

        update_cash = user_cash + transaction_value

        # Checking if conditions are true

        if not symbol:
            return apology("User did not provide symbol")

        if stock == None:
            return apology("Symbol does not exists")

        if shares > user_shares:
            return apology("User is trying to sell more shares that he/she owns")

        if shares <= 0:
            return apology("Invalid number of shares")

        db.execute("INSERT INTO transactions VALUES (?, ?, ?, ?, ?, ?)", id,
                   stock["name"], stock["symbol"], stock["price"], (-1) * shares, str(datetime.now()))
        db.execute("UPDATE users SET cash = ? WHERE id = ?", update_cash, id)

        db_updated_shares = db.execute(
            "SELECT SUM(quantity) AS shares FROM transactions WHERE username = ? AND symbol = ?", id, symbol)
        updated_shares = db_updated_shares[0]["shares"]

        flash("Sold!")

        return redirect("/")