#!/bin/bash
#
# Exercise 17 - Simple Database - Test script
# This script tests the actions of the simple database.

# abort on error
set -e

echo "Time to test!" | fembot3

# create action test
./ex17 testdb.dat c

# set action test
./ex17 testdb.dat s 0 Anthony anthony@example.com
./ex17 testdb.dat s 1 Zed zed@example.com
./ex17 testdb.dat s 2 Frank frank@example.com
./ex17 testdb.dat s 3 Joe joe@example.com
./ex17 testdb.dat s 4 Ashley ashley@example.com
./ex17 testdb.dat s 5 Zora zora@example.com
./ex17 testdb.dat s 6 Fawn fawn@example.com
./ex17 testdb.dat s 7 Julie julie@example.com
./ex17 testdb.dat s 8 Melinda mindy@example.com
./ex17 testdb.dat s 9 Samantha sam@example.com

# list action test
./ex17 testdb.dat l

# get action test
# use the get action to retrieve all the even numbered Address records
ID=0
while [ $ID -lt 10 ]; do
    ./ex17 testdb.dat g $ID
    let ID=ID+2
done

# delete action test
./ex17 testdb.dat d 3

# list after delete
./ex17 testdb.dat l

echo "Testing complete." | fembot3
