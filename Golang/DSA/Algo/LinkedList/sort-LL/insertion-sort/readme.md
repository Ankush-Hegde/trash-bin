Complexity Analysis

Time Complexity:
- Worst case: $O(n²)$ when the elements arrive in reverse sequential order, demanding a full traversal back to the start for every insertion.
- Best case: $O(n)$ if the list is completely sorted at the start, as the shortcut condition prevents inner scans entirely.

Space Complexity: $O(1)$ because the transformation rearranges memory addresses in-place instead of constructing entirely new arrays or lists