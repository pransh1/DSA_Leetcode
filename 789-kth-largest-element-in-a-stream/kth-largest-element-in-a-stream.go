package main

import (
	"sort"
)

type KthLargest struct {
	k       int
	largest []int
}

func Constructor(k int, nums []int) KthLargest {
	// Sort the nums initially
	sort.Ints(nums)
	return KthLargest{
		k:       k,
		largest: nums,
	}
}

func (this *KthLargest) Add(val int) int {
	// Binary search to find the correct position to insert 'val'
	index := sort.SearchInts(this.largest, val)
	
	// Insert at the found index to keep the array sorted
	this.largest = append(this.largest[:index], append([]int{val}, this.largest[index:]...)...)

	// Return the k-th largest (so from the end)
	return this.largest[len(this.largest)-this.k]
}
