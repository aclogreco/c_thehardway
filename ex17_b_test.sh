#!/bin/bash
#
# Exercise 17 version B - Simple Database - Test script
# This script tests the actions of the simple database.

# abort on error
set -e

echo "Time to test!" | fembot3

# create action test
echo "Create action test."
./ex17_b testdb_b.dat c 10 256
echo "Create action test complete."
echo

# set action test
echo "Set action test."
./ex17_b testdb.dat s 0 Anthony anthony@example.com
./ex17_b testdb.dat s 1 Zed zed@example.com
./ex17_b testdb.dat s 2 Frank frank@example.com
./ex17_b testdb.dat s 3 Joe joe@example.com
./ex17_b testdb.dat s 4 Ashley ashley@example.com
./ex17_b testdb.dat s 5 Zora zora@example.com
./ex17_b testdb.dat s 6 Fawn fawn@example.com
./ex17_b testdb.dat s 7 Julie julie@example.com
./ex17_b testdb.dat s 8 Melinda mindy@example.com
./ex17_b testdb.dat s 9 Samantha sam@example.com
echo "Set action test complete."
echo

# list action test
echo "List action test."
./ex17_b testdb.dat l
echo "List action test complete."
echo

# get action test
# use the get action to retrieve all the even numbered Address records
echo "Get action test."
ID=0
while [ $ID -lt 10 ]; do
    ./ex17_b testdb.dat g $ID
    let ID=ID+2
done
echo "Get action test complete."
echo

# delete action test
echo "Delete action test."
./ex17_b testdb.dat d 3
echo "Delete action test complete."
echo

# list after delete
echo "Final list."
./ex17_b testdb.dat l
echo

echo "Testing complete." | fembot3
