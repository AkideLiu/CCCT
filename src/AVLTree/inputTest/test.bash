#!/bin/bash

input="AVLTree_testSet.txt"

$(g++ ./*.cpp ../*.cpp -o main.out --std=c++11 -Wall)

if [ $? -ne 0 ]; then
  exit 1;
fi

if [ -f input.txt ]; then
    rm -rf input.txt
fi

if [ -f compare.txt ]; then
    rm -rf compare.txt
fi
if [ -f out.txt ]; then
    rm -rf out.txt
fi



while IFS= read -r line
do
  input_data=$(echo "$line" | grep 'For input' | sed s/For\ input\ //g)
  echo "$input_data" | grep -E 'A|D' >> input.txt

  correct=$(echo "$line" | grep 'Output shouldbe' | sed s/Output\ shouldbe\ \ //g)
  echo "$correct" | grep . | awk '{print $0" "}' >> compare.txt


done < "$input"


while IFS= read -r line
do

  result=$(echo "$line" | ./main.out)
  echo "$result" >> out.txt


done < "input.txt"

#https://github.com/so-fancy/diff-so-fancy

if ! command -v diff-so-fancy &> /dev/null
then
  diff_so_fancy_flag="false";
fi

if [ "$(uname -s)" == "Linux" ] && [ "$diff_so_fancy_flag" == "false" ]; then
  sudo add-apt-repository -y ppa:aos1/diff-so-fancy
  sudo apt-get update
  sudo apt-get -y install diff-so-fancy
  diff_so_fancy_flag=true;
fi

if [ "$(uname -s)" == "Darwin" ] && [ "$diff_so_fancy_flag" == "false" ];then
  brew install diff-so-fancy
  diff_so_fancy_flag=true;
fi




if [ "$diff_so_fancy_flag" == "false" ]; then
    diff out.txt compare.txt
else
    diff -u out.txt compare.txt | diff-so-fancy
fi

RED='\033[0;31m'
GREEN='\033[0;32m'
NC='\033[0m' # No Color

echo -e "${RED}========================================================"
echo -e "${GREEN}if the diff content is too long, use : "

if [ "$diff_so_fancy_flag" == "false" ]; then
    echo -e "${GREEN}diff out.txt compare.txt | less -R"
else
    echo -e "${GREEN}diff -u out.txt compare.txt | diff-so-fancy | less -R"
fi

echo -e "${RED}========================================================${NC}"




if [ -f main.out ]; then
    rm -rf main.out
fi