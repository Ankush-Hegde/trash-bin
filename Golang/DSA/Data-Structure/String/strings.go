package main

import (
	"fmt"
	"unicode/utf8"
)

func main() {
	// "Hi" uses 1 byte per character.
	// "Gó" contains 'ó', which takes 2 bytes in UTF-8.
	str := "Gó"
	english := "Hello"
	emoji := "🚀"
	thai := "สวัสดี"

	fmt.Println("--- 1. String Inspection ---")
	// len() measures the number of BYTES, not characters!
	// --- 1. String Inspection ---
	// String: Gó | Byte Length: 3
	// Actual Character Count (Runes): 2
	fmt.Printf("String: %s | Byte Length: %d\n", str, len(str))

	// utf8.RuneCountInString measures actual characters (runes)
	fmt.Printf("Actual Character Count (Runes): %d\n\n", utf8.RuneCountInString(str))

	fmt.Println("--- 2. Indexing (Byte-by-Byte Loop) ---")
	// Using a traditional counter loop accesses individual raw bytes
	// --- 2. Indexing (Byte-by-Byte Loop) ---
	// Index 0: Hex: 47 | Cast to String: G
	// Index 1: Hex: c3 | Cast to String: Ã
	// Index 2: Hex: b3 | Cast to String: ³
	for i := 0; i < len(str); i++ {
		fmt.Printf("Index %d: Hex: %x | Cast to String: %s\n", i, str[i], string(str[i]))
	}
	// Note: Printing the individual bytes of 'ó' separately produces corrupted text/fragments!

	fmt.Println("\n--- 3. Ranging (Rune-by-Rune Loop) ---")
	// 'for range' automatically decodes UTF-8 into runes on the fly
	// --- 3. Ranging (Rune-by-Rune Loop) ---
	// Byte Position 0: Character: G | Unicode Code Point: U+0047
	// Byte Position 1: Character: ó | Unicode Code Point: U+00F3
	for index, runeValue := range str {
		fmt.Printf("Byte Position %d: Character: %c | Unicode Code Point: %U\n", index, runeValue, runeValue)
	}

	fmt.Println("\n--- 4. Type Conversions ---")
	// Convert string to slice of bytes
	// --- 4. Type Conversions ---
	// Slice of Bytes: [71 195 179]
	// Slice of Runes: [71 243]
	byteSlice := []byte(str)
	fmt.Println("Slice of Bytes:", byteSlice)

	// Convert string to slice of runes
	runeSlice := []rune(str)
	fmt.Println("Slice of Runes:", runeSlice)

	// Use the built-in len() function. This measures the
	// memory size. It is fast and efficient, but it will
	// return misleading counts for non-English text or emojis
	fmt.Println(len(str)) // Output: 3 (G is 1 byte, ó is 2 bytes)

	// Use the unicode/utf8 package. This inspects the text and counts the actual Unicode
	// code points, giving you the true visual character count
	fmt.Println(utf8.RuneCountInString(str)) // Output: 2

	// English (ASCII) - Bytes and Runes match exactly
	fmt.Printf("%s -> len(): %d | RuneCount: %d\n",
		english, len(english), utf8.RuneCountInString(english))

	// Emoji - 1 visual character takes 4 bytes
	fmt.Printf("%s -> len(): %d | RuneCount: %d\n",
		emoji, len(emoji), utf8.RuneCountInString(emoji))

	// Thai - 5 visual characters take 15 bytes (3 bytes per rune)
	fmt.Printf("%s -> len(): %d | RuneCount: %d\n",
		thai, len(thai), utf8.RuneCountInString(thai))
}
