#!/bin/bash

# Check if a day number was provided
if [ $# -eq 1 ]; then
    DAY=$(printf "%02d" $1)
else
    echo "Usage: $0 <day-number>"
    exit 1
fi

# Path to the day's executable
EXECUTABLE="./build/day${DAY}/day${DAY}"

# Check if the executable exists
if [ -f "$EXECUTABLE" ]; then
    # Run the executable
    $EXECUTABLE
else
    echo "Executable for day${DAY} not found."
    exit 1
fi
