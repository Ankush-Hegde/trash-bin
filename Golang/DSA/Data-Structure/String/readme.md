In Go, a string is an immutable, read-only slice of bytes, which typically stores UTF-8 encoded text.

To master text processing in Go, you must understand three core concepts: strings, bytes, and runes

Quick Summary: Byte vs. Rune

| Feature | byte | rune |
|---------|-------|------|
| Underlying Type | Alias for `uint8` (8-bit unsigned integer) | Alias for int32 (32-bit signed integer) | 
| Max Value | 255 (Can only hold English ASCII characters) | 2,147,483,647 (Can hold any Unicode code point) |
| Literal Syntax | Enclosed in single quotes (e.g., 'A') |Enclosed in single quotes (e.g., '🗺️') | 
| String Behavior | Indexing a string (s[i]) returns a `byte` |Ranging a string (for range s) yields a rune |

1. What is a Byte?<br>
A byte represents 8 bits of data. Standard English text (ASCII characters like `A`, `b`, `7`, `$`) fits perfectly inside a single byte. However, special characters like accented letters (`é`), non-Latin scripts (`สวัสดี`), or emojis (`🚀`) require anywhere from 2 to 4 bytes to be stored in UTF-8.
2. What is a Rune?<br>
A `rune` represents a single Unicode code point. Because it is a 32-bit integer, it is large enough to represent every single character, symbol, or emoji in existence, regardless of how many bytes it occupies on disk.

⚠️ Essential String Rules to Remember
- Immutability: Strings cannot be modified in place. `s[0] = 'X'` will throw a compiler error. You must convert the string to a `[]byte` or `[]rune`, make changes, and cast it back to a `string`.
- Beware of `len():` Always remember that `len(mystring)` calculates bytes. If you are processing international text or emojis, use utf8.RuneCountInString() instead.
- Iteration Tricks: A `for i := 0...` loop gives you raw bytes. A `for i, r :=` range loop gives you decoded runes, but notice how the index jumps from `1` to `3` in the example above because the character at position 1 took up 2 bytes