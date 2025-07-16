# Test Suite Documentation

## 📂 Test Files Overview

This directory contains comprehensive test cases for the Social Media Platform implementation. All test files follow a standardized format and cover different aspects of the system.

### 🧪 Test Categories

#### 1. **Basic Functionality Tests**
- **File**: `test_input.txt`
- **Operations**: 25 test cases
- **Focus**: Core functionality validation
- **Coverage**: Post creation, comments, replies, navigation
- **Expected Runtime**: < 5 seconds

#### 2. **Edge Cases & Boundary Testing**
- **File**: `test_edge_clean.txt` 
- **Operations**: 60+ test cases
- **Focus**: Boundary conditions and error handling
- **Coverage**: Invalid indices, empty states, null operations
- **Expected Runtime**: < 10 seconds

#### 3. **Comprehensive Edge Cases**
- **File**: `test_edge_cases.txt`
- **Operations**: 80+ test cases (with comments)
- **Focus**: Detailed edge case documentation
- **Coverage**: All possible error scenarios
- **Expected Runtime**: < 15 seconds

#### 4. **Stress Testing**
- **File**: `test_stress.txt`
- **Operations**: 200+ test cases
- **Focus**: System performance under load
- **Coverage**: Multiple posts, comments, complex operations
- **Expected Runtime**: < 30 seconds

#### 5. **Mini Stress Testing**
- **File**: `test_stress_mini.txt`
- **Operations**: 50+ test cases
- **Focus**: Quick stress validation
- **Coverage**: Essential stress scenarios
- **Expected Runtime**: < 10 seconds

#### 6. **Memory Safety Testing**
- **File**: `test_memory.txt`
- **Operations**: 40+ test cases
- **Focus**: Memory management validation
- **Coverage**: Allocation/deallocation patterns
- **Expected Runtime**: < 8 seconds

#### 7. **Production Validation**
- **File**: `test_final_validation.txt`
- **Operations**: 25 test cases
- **Focus**: Real-world usage scenarios
- **Coverage**: Complete workflows
- **Expected Runtime**: < 5 seconds

## 🚀 Running Tests

### Quick Test (Basic functionality)
```bash
# From project root directory
./social_media < tests/test_input.txt
```

### Comprehensive Test Suite
```bash
# Run all tests
for test_file in tests/test_*.txt; do
    echo "Running $test_file..."
    ./social_media < "$test_file"
    echo "---"
done
```

### Individual Test Categories
```bash
# Basic functionality
./social_media < tests/test_input.txt

# Edge cases
./social_media < tests/test_edge_clean.txt

# Stress testing
./social_media < tests/test_stress.txt

# Memory safety
./social_media < tests/test_memory.txt

# Production validation
./social_media < tests/test_final_validation.txt
```

### Using Makefile (if available)
```bash
# Run basic tests
make test

# Run comprehensive test suite
make test-all
```

## 📊 Expected Test Results

### ✅ Success Indicators
- Posts display with proper formatting (`------------`)
- Comments show with asterisk borders (`**************`)
- Error messages appear for invalid operations
- No segmentation faults or crashes
- Graceful handling of edge cases

### ❌ Failure Indicators
- Segmentation fault
- Program hanging/freezing
- Unexpected crashes
- Memory leaks (if using valgrind)
- Inconsistent output formatting

## 🔍 Test Result Analysis

### Normal Output Patterns
```
------------        # Post header
username           # Post author
content            # Post content

**************     # Comment header  
username           # Comment author
content            # Comment content

Failed to add comment    # Expected error message
Unknown command: xyz     # Input validation
No comments to print     # Empty state handling
```

### Performance Benchmarks
```
Test Category        | Operations | Expected Time | Memory Usage
---------------------|------------|---------------|-------------
Basic Functionality  | 25         | < 5s         | < 2MB
Edge Cases           | 60+        | < 10s        | < 3MB
Stress Testing       | 200+       | < 30s        | < 8MB
Memory Safety        | 40+        | < 8s         | < 2MB
Production Validation| 25         | < 5s         | < 2MB
```

## 🧰 Testing Tools & Commands

### Memory Leak Detection (Linux/macOS)
```bash
# Install valgrind
sudo apt install valgrind

# Run with memory leak detection
valgrind --leak-check=full --show-leak-kinds=all \
    ./social_media < tests/test_input.txt
```

### Performance Monitoring
```bash
# Time execution
time ./social_media < tests/test_stress.txt

# Detailed resource usage
/usr/bin/time -v ./social_media < tests/test_stress.txt
```

### Custom Test Creation
```bash
# Create custom test file
cat > tests/my_custom_test.txt << EOF
add_post testuser "Custom test"
view_post 1
add_comment reviewer "Test comment"
view_comments
exit
EOF

# Run custom test
./social_media < tests/my_custom_test.txt
```

## 📈 Test Coverage Matrix

| Feature Category | Basic | Edge | Stress | Memory | Production |
|------------------|-------|------|--------|--------|------------|
| Post Creation    | ✅    | ✅   | ✅     | ✅     | ✅         |
| Post Viewing     | ✅    | ✅   | ✅     | ✅     | ✅         |
| Post Deletion    | ✅    | ✅   | ✅     | ✅     | ✅         |
| Comment System   | ✅    | ✅   | ✅     | ✅     | ✅         |
| Reply System     | ✅    | ✅   | ✅     | ✅     | ✅         |
| Navigation       | ✅    | ✅   | ✅     | ✅     | ✅         |
| Error Handling   | ❌    | ✅   | ✅     | ✅     | ✅         |
| Memory Safety    | ❌    | ✅   | ✅     | ✅     | ❌         |
| Boundary Cases   | ❌    | ✅   | ✅     | ✅     | ❌         |
| Performance      | ❌    | ❌   | ✅     | ✅     | ❌         |

## 🎯 Quality Assurance Checklist

### Before Running Tests
- [ ] Code compiles without warnings
- [ ] All source files are present
- [ ] Executable has proper permissions
- [ ] Test files are in correct directory

### During Testing
- [ ] No segmentation faults occur
- [ ] Error messages are user-friendly
- [ ] Memory usage stays reasonable
- [ ] Performance meets expectations

### After Testing
- [ ] All tests complete successfully
- [ ] Output formatting is consistent
- [ ] No memory leaks detected
- [ ] System resources are freed

## 🚨 Troubleshooting Test Issues

### Common Problems

**Test file not found**
```bash
# Ensure you're in the project root directory
ls -la tests/
# Should show all test_*.txt files
```

**Permission denied**
```bash
# Make executable
chmod +x social_media
```

**Program hangs**
```bash
# Check input format - avoid spaces in usernames/content
# Use simple alphanumeric strings
```

**Unexpected crashes**
```bash
# Compile with debug symbols
gcc -g -Wall -Wextra -std=c99 -o social_media_debug \
    code/main.c code/comment.c code/platform.c code/post.c code/reply.c

# Run with debugger
gdb ./social_media_debug
(gdb) run < tests/test_input.txt
```

## 📝 Test File Format

All test files follow this format:
```
command1 param1 param2
command2 param1
command3 param1 param2 param3
...
exit
```

### Valid Commands
- `add_post <username> <caption>`
- `view_post <n>`
- `delete_post <n>`
- `add_comment <username> <content>`
- `view_comments`
- `delete_comment <n>`
- `add_reply <username> <content> <n>`
- `delete_reply <n> <m>`
- `current_post`
- `next_post`
- `previous_post`
- `exit`

---

**Total Test Coverage: 300+ operations across 7 test files**
**Estimated Total Runtime: < 2 minutes for complete test suite**
**Quality Assurance Level: Production-ready**
