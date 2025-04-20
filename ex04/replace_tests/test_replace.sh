#!/bin/bash

RESET="\033[0m"
GREEN="\033[32m"
BLUE="\033[34m"
RED="\033[31m"
YELLOW="\033[33m"
EXEC=./replace_text
SUCCESS=0
FAIL=0

function run_test() {
    description=$1
    command=$2
    input=$3
    expected=$4
    output="${input}.replace"

    printf "\n${BLUE}Test: $description ...${RESET}\n\n"
    sleep 2
    eval "$command"

    if [[ ! -f "$output" ]]; then
        echo "${RED}❌ Output file not created.${RESET}"
        ((FAIL++))
        return
    fi
    sleep 1
    if [[ $(cat "$expected") == $(cat "${output}") ]]; then
        echo "${YELLOW}\n---------------------------------\n${RESET}"
        echo "${GREEN}✅ Test passed.\n"
        echo "Expected:${RESET}"
        cat "$expected"
        echo "\n"
        echo "${GREEN}Output:${RESET}"
        cat "$output"
        echo "${YELLOW}\n---------------------------------${RESET}"
        ((SUCCESS++))
    else
        echo "${YELLOW}\n---------------------------------\n${RESET}"
        echo "${RED}❌ Test failed.\n"
        echo "Output file created but content does not match.\n"
        echo "Expected:${RESET}"
        cat "$expected"
        echo "\n"
        echo "${RED}Got:${RESET}"
        cat "${output}"
        echo "${YELLOW}\n---------------------------------${RESET}"
        ((FAIL++))
    fi
}

# Preparar archivos de prueba
printf "${BLUE}Running tests ...${RESET}\n\n"

make >/dev/null
echo "Hello world" > test1.txt
echo "Hello universe" > test1.expected
run_test "Replace 'world' with 'universe'" "$EXEC test1.txt world universe" "test1.txt" "test1.expected"

echo "foo bar foo bar" > test2.txt
echo "baz bar baz bar" > test2.expected
run_test "Replace 'foo' with 'baz'" "$EXEC test2.txt foo baz" "test2.txt" "test2.expected"

sleep 2

# Casos de error
echo "\n\n${BLUE}Running error tests ... ${RESET}\n"

echo "${YELLOW}----------------------------------${RESET}"
echo "\n${BLUE}Test: Missing arguments ...${RESET}\n"

if $EXEC; then
    echo "${RED}❌ Test failed${RESET}\n" 
    ((FAIL++))
else
    echo "${GREEN}\n✅ Controlled error${RESET}\n"
    ((SUCCESS++))
fi
sleep 1

echo "${YELLOW}----------------------------------${RESET}"
echo "\n${BLUE}Test: File does not exist ...${RESET}\n"

if $EXEC nofile.txt a b; then
    echo "${RED}❌ Test failed${RESET}\n" 
    ((FAIL++))
else
    echo "${GREEN}\n✅ Controlled error${RESET}\n"
    ((SUCCESS++))
fi
sleep 1

echo "${YELLOW}----------------------------------${RESET}"
echo "\n${BLUE}Test: s1 is empty ...${RESET}\n"

if $EXEC test1.txt "" b; then
    echo "${RED}❌ Test failed${RESET}\n" 
    ((FAIL++))
else
    echo "${GREEN}\n✅ Controlled error${RESET}\n"
    ((SUCCESS++))
fi
sleep 1

echo "${YELLOW}----------------------------------${RESET}"
echo "\n${BLUE}Test: s1 == s2 ...${RESET}\n"

if $EXEC test1.txt same same; then
    echo "${RED}❌ Test failed${RESET}\n" 
    ((FAIL++))
else
    echo "${GREEN}\n✅ Controlled error${RESET}\n"
    ((SUCCESS++))
fi
sleep 1

echo "${YELLOW}----------------------------------${RESET}"
echo "\n${BLUE}Test: matches not found ...${RESET}\n"
if $EXEC test1.txt notfound notfound2; then
    echo "${RED}❌ Test failed${RESET}\n" 
    ((FAIL++))
else
    echo "${GREEN}\n✅ Controlled error${RESET}\n"
    ((SUCCESS++))
fi

sleep 2
echo "\n${YELLOW}----------------------------------${RESET}"
echo "${GREEN}Tests passed: $SUCCESS ${RESET}"
echo "${RED}Tests failed: $FAIL ${RESET}"
echo "${YELLOW}----------------------------------${RESET}"
echo "\n${BLUE}All tests finished.${RESET}\n"

rm -f test*
make fclean >/dev/null