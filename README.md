# Social Media Platform - Data Structures Project

## Overview
A comprehensive social media platform implementation in C featuring posts, comments, and replies with full CRUD operations and navigation capabilities.

## Features

### Core Functionality
- ✅ **Post Management**: Create, view, delete posts
- ✅ **Comment System**: Add comments to posts, view all comments
- ✅ **Reply System**: Reply to specific comments
- ✅ **Navigation**: Navigate between posts (previous, current, next)
- ✅ **Memory Management**: Proper allocation and deallocation
- ✅ **Error Handling**: Comprehensive edge case coverage

### Data Structures Used
- **Linked Lists**: For posts, comments, and replies
- **Platform Structure**: Main container for the social media platform
- **Dynamic Memory**: All strings are dynamically allocated

## Architecture

### File Structure
```
code/
├── main.c          # Main program and user interface
├── platform.c/.h   # Platform management functions
├── post.c/.h       # Post creation and management
├── comment.c/.h    # Comment system implementation
└── reply.c/.h      # Reply system implementation
```

### Data Structure Hierarchy
```
Platform
└── Posts (Linked List)
    └── Comments (Linked List)
        └── Replies (Linked List)
```

## Commands

### Post Operations
- `add_post <username> <caption>` - Create a new post
- `view_post <n>` - View the nth post (1-based indexing)
- `delete_post <n>` - Delete the nth post
- `current_post` - Display currently viewed post
- `next_post` - Navigate to next post
- `previous_post` - Navigate to previous post

### Comment Operations
- `add_comment <username> <content>` - Add comment to current post
- `view_comments` - Display all comments of current post
- `delete_comment <n>` - Delete nth comment from current post

### Reply Operations
- `add_reply <username> <content> <n>` - Reply to nth comment
- `delete_reply <n> <m>` - Delete mth reply from nth comment

### System Operations
- `exit` - Exit the program

## Building and Running

### Prerequisites
- GCC compiler
- Make utility (optional)

### Build Options

#### Using Makefile (Recommended)
```bash
make                # Build the program
make run           # Build and run
make test          # Run basic tests
make test-all      # Run comprehensive test suite
make clean         # Clean build files
make debug         # Build with debug symbols
make release       # Build optimized version
```

#### Manual Compilation
```bash
gcc -Wall -Wextra -std=c99 -g -o social_media code/main.c code/comment.c code/platform.c code/post.c code/reply.c
```

## Testing

### Test Suites Available
1. **test_input.txt** - Basic functionality tests
2. **test_edge_cases.txt** - Edge case and error handling tests  
3. **test_stress.txt** - Stress testing with complex scenarios
4. **test_memory.txt** - Memory safety and boundary tests

### Running Tests
```bash
# Run individual test suites
./social_media < test_input.txt
./social_media < test_edge_cases.txt
./social_media < test_stress.txt
./social_media < test_memory.txt

# Or use makefile
make test-all
```

## Edge Cases Handled

### Input Validation
- ✅ Null pointer checks for all parameters
- ✅ Invalid indices (negative, zero, out of bounds)
- ✅ Buffer overflow protection in input
- ✅ Memory allocation failure handling

### Data Structure Edge Cases
- ✅ Operations on empty platform
- ✅ Navigation beyond list boundaries
- ✅ Deletion of non-existent items
- ✅ Access to deleted items
- ✅ Complex deletion chain reactions

### Memory Management
- ✅ Proper string copying (using strdup)
- ✅ Memory cleanup on failures
- ✅ Nested structure cleanup
- ✅ Prevention of memory leaks

### Navigation Edge Cases
- ✅ Navigation without posts
- ✅ Navigation after deletions
- ✅ Boundary navigation (first/last posts)
- ✅ Invalid post access

## Implementation Details

### Memory Safety
- All dynamic memory is properly allocated and freed
- String operations use safe functions (strdup, bounds-checked scanf)
- Comprehensive null pointer checking
- Memory cleanup functions for nested structures

### Error Handling
- Return values indicate success/failure for all operations
- Graceful handling of invalid operations
- User-friendly error messages
- Robust input validation

### Performance Considerations
- O(n) access time for indexed operations
- Efficient memory usage with dynamic allocation
- Minimal memory fragmentation

## Known Limitations
- Sequential access for indexed operations (not random access)
- Memory not freed on program exit (operating system handles cleanup)
- Single platform instance (no multi-platform support)

## Future Enhancements
- Hash tables for O(1) post access
- User authentication system
- Persistent storage (file I/O)
- Advanced search functionality
- Memory pool allocation

## Testing Results
The platform successfully handles:
- ✅ 20+ simultaneous posts
- ✅ 10+ comments per post
- ✅ Multiple replies per comment
- ✅ Complex deletion scenarios
- ✅ All edge cases and boundary conditions
- ✅ Memory safety under stress testing

## Contributors
- Student ID: 2023102006
- Data Structures and Algorithms Assignment

## License
Academic Project - For Educational Use Only
