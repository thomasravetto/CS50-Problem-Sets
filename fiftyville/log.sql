-- Keep a log of any SQL queries you execute as you solve the mystery.

-- Checking the crime_scene_reports table to look at crimes happened on July 28th on Humphrey Street
SELECT description
FROM crime_scene_reports
WHERE year = 2021 AND month = 7 AND day = 28
AND street = "Humphrey Street";
-- Theft took place at 10:15am at the street's bakery

-- Looking at interview reports to check some details on the theft, checking id, name and transcript
SELECT id, name, transcript
FROM interviews
WHERE year = 2021 AND month = 7 AND day = 28;
-- ID 161 Ruth saw the thief get into a car at the bakery parking lot
-- ID 162 Eugene said that he doesn't know the thief name but it is someone that he recognized, he saw the thief withdrawing some money on Leggett Street ATM beofre arriving to the bakery
-- ID 163 Raymond said that the thied called someone for less than a minute when he left and said to buy a flight ticket for tomorrow

-- LIST:
-- Phone call that lasted less than a minute: Benista, Bruce, Carina, Diana, Kathryn, Kelsey, Kenny, Sofia, Taylor.
-- People who drove away from the bakety parking lot: Bruce, Diana, Kelsey, Sofia.
-- People who were seen withdrawing money before the theft: Bruce, Diana.


-- Looking for a phone call that lasts less than a minute
SELECT duration, caller, receiver
FROM phone_calls
WHERE year = 2021 AND month = 7 AND day = 28 AND duration <= 60
ORDER BY duration;
-- There are 10 phone calls, checking to see if I can go back to the callers' name
SELECT name FROM people WHERE phone_number IN (SELECT caller FROM phone_calls WHERE year = 2021 AND month = 7 AND day = 28 AND duration <= 60);

-- Checking bakery security logs and searching for the licence plates
SELECT name FROM people WHERE license_plate IN (SELECT license_plate FROM bakery_security_logs WHERE year = 2021 AND month = 7 AND day = 28 AND hour = 10 AND minute BETWEEN 15 AND 30);

-- Finding people that were leaving the parking lot within ten minutes and that made a call that lasted less than a minute
SELECT name FROM people WHERE name IN (SELECT name FROM people WHERE license_plate IN (SELECT license_plate FROM bakery_security_logs WHERE year = 2021 AND month = 7 AND day = 28 AND hour = 10 AND minute BETWEEN 15 AND 25) AND name IN (SELECT name FROM people WHERE phone_number IN (SELECT caller FROM phone_calls WHERE year = 2021 AND month = 7 AND day = 28 AND duration <= 60)));
-- Possible suspects are Diana, Sofia, Kelsey, Bruce

-- Trying to find out if any of the suspects withdrew some money on Leggett Street before the theft, i'm using the previous code to check if the suspect is in the list of people who had a phone call that lasted less than a minute and that were seen leaving the parking lot of the bakery
SELECT name FROM people WHERE id IN (SELECT person_id FROM bank_accounts WHERE account_number IN (SELECT account_number FROM atm_transactions WHERE year = 2021 AND month = 7 AND day = 28 AND atm_location = "Leggett Street")) AND name IN (SELECT name FROM people WHERE name IN (SELECT name FROM people WHERE license_plate IN (SELECT license_plate FROM bakery_security_logs WHERE year = 2021 AND month = 7 AND day = 28 AND hour = 10 AND minute BETWEEN 15 AND 25) AND name IN (SELECT name FROM people WHERE phone_number IN (SELECT caller FROM phone_calls WHERE year = 2021 AND month = 7 AND day = 28 AND duration <= 60))));
-- Now i have to see if one of the suspects has taken a flight the day after the theft and who was the accomplice
-- I have to check where both of the suspects went with their flight
SELECT full_name, abbreviation FROM airports WHERE id IN (SELECT destination_airport_id FROM flights WHERE id IN (SELECT flight_id FROM passengers WHERE passport_number IN (SELECT passport_number FROM people WHERE name = "Bruce")) AND year = 2021 AND month = 7 AND day = 29 AND hour BETWEEN 00 AND 8);
-- Suspect Bruce went to LaGuardia Airport (LGA)
SELECT full_name, abbreviation FROM airports WHERE id IN (SELECT destination_airport_id FROM flights WHERE id IN (SELECT flight_id FROM passengers WHERE passport_number IN (SELECT passport_number FROM people WHERE name = "Diana")) AND year = 2021 AND month = 7 AND day = 29);
-- Suspect Diana went to Logan International Airpot (BOS)

-- The first flight is the one to new york so bruce must be the thief, and he called robin so she must be the accomplice.