import os

from cs50 import SQL
from flask import Flask, flash, jsonify, redirect, render_template, request, session

# Configure application
app = Flask(__name__)

# Ensure templates are auto-reloaded
app.config["TEMPLATES_AUTO_RELOAD"] = True

# Configure CS50 Library to use SQLite database
db = SQL("sqlite:///birthdays.db")


@app.after_request
def after_request(response):
    """Ensure responses aren't cached"""
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response



@app.route("/", methods=["GET", "POST"])
def index():
    if request.method == "POST":

        # TODO: Add the user's entry into the database
        name = request.form.get("name")
        month = request.form.get("month")
        day = request.form.get("day")
        if not name or not month or not day:
            return redirect("/")

        db.execute("INSERT INTO birthdays (name, month, day) VALUES (?, ?, ?)", name, month, day)
        return redirect("/")

    else:
        BIRTHDAYS = db.execute("SELECT * FROM birthdays")
        # TODO: Display the entries in the database on index.html

        return render_template("index.html", birthdays=BIRTHDAYS)

@app.route("/delete", methods=["POST"])
def delete():
    delete_id = request.form.get("delete")
    db.execute("DELETE FROM birthdays WHERE id = ?", delete_id)
    return redirect("/")

@app.route("/edit", methods=["POST"])
def edit():
    month = request.form.get("month")
    day = request.form.get("day")
    edit_id = request.form.get("id")
    db.execute("UPDATE birthdays SET month = ?, day = ? WHERE id = ?", month, day, edit_id)
    return redirect("/")
