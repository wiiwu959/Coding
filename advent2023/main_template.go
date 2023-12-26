package main

import (
	"fmt"
	"advent/helper"
)

// go mod edit -replace advent/helper=../helper
// go mod tidy
func main() {
	inputLines := helper.ReadInput("input.txt");

	var part1 int = 0
	var part2 int = 0

	for index, eachLine := range inputLines {
		// Do somthing
	}

	fmt.Printf("Answer of Part 1 is %d \n", part1)
	fmt.Printf("Answer of Part 2 is %d \n", part2)
	
}