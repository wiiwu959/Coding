package main

import (
	"fmt"
	"unicode"
	"strings"
	"advent/helper"
)

func getNum(proccessLine string) int {
	var num int = 0
	var finded bool = false
	var lastWord rune
	
	for _, word := range proccessLine {
		if unicode.IsDigit(word) {
			if !finded {
				finded = true;
				num = 10 * int(word - '0')
			}
			lastWord = word
		}
	}

	num += int(lastWord - '0')
	return num
}

func findAllSubstringIndices(s, substr string) []int {
	var indices []int
	index := 0

	// This is while in golang
	for {
		pos := strings.Index(s[index:], substr)
		if pos == -1 {
			break
		}

		index += pos
		indices = append(indices, index)

		index += len(substr)
	}

	return indices
}

func getStingNum(proccessLine string) int {
	var first int = 0;
	var last int = 0;

	var firstIndex int = len(proccessLine)
	var lastIndex int = -1
	numList := []string {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"}

	for index, num := range numList {
		indices := findAllSubstringIndices(proccessLine, num)
		if (len(indices) > 0) {
			if (indices[0] < firstIndex) {
				firstIndex = indices[0]
				first = index + 1
			}
			
			if (indices[len(indices) - 1] > lastIndex) {
				lastIndex = indices[len(indices) - 1]
				last = index + 1
			}
		}
	}

	for index, word := range proccessLine {
		if unicode.IsDigit(word) {
			if (index < firstIndex) {
				firstIndex = index
				first = int(word - '0')
			}
			
			if (index > lastIndex) {
				lastIndex = index
				last = int(word - '0')
			}
		}
	}

	num := first * 10 + last
	return num
}

func main() {
	inputLines := helper.ReadInput("input.txt");

	// part 1
	var sum int = 0
	for _, eachLine := range inputLines {
		sum += getNum(eachLine)
	}
	fmt.Printf("Answer of Part 1 is %d \n", sum)

	// part 2
	sum = 0
	for _, eachLine := range inputLines {
		sum += getStingNum(eachLine)
	}
	fmt.Printf("Answer of Part 2 is %d \n", sum)
}