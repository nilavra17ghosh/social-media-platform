#!/bin/bash

# Social Media Platform Test Runner
# This script runs all test cases and provides a summary

echo "🚀 Social Media Platform - Comprehensive Test Suite"
echo "=================================================="
echo ""

# Colors for output
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
BLUE='\033[0;34m'
NC='\033[0m' # No Color

# Test results tracking
TESTS_PASSED=0
TESTS_FAILED=0
START_TIME=$(date +%s)

# Function to run a test
run_test() {
    local test_file=$1
    local test_name=$2
    
    echo -e "${BLUE}🧪 Running $test_name...${NC}"
    
    if [ -f "tests/$test_file" ]; then
        if ./social_media < "tests/$test_file" > /dev/null 2>&1; then
            echo -e "${GREEN}✅ $test_name PASSED${NC}"
            ((TESTS_PASSED++))
        else
            echo -e "${RED}❌ $test_name FAILED${NC}"
            ((TESTS_FAILED++))
        fi
    else
        echo -e "${RED}❌ Test file tests/$test_file not found${NC}"
        ((TESTS_FAILED++))
    fi
    echo ""
}

# Check if executable exists
if [ ! -f "social_media" ]; then
    echo -e "${RED}❌ social_media executable not found. Please compile first:${NC}"
    echo "gcc -Wall -Wextra -std=c99 -g -o social_media code/main.c code/comment.c code/platform.c code/post.c code/reply.c"
    exit 1
fi

echo -e "${YELLOW}📋 Test Categories:${NC}"
echo "1. Basic Functionality Tests"
echo "2. Edge Cases & Boundary Testing"  
echo "3. Stress Testing"
echo "4. Memory Safety Testing"
echo "5. Production Validation"
echo ""

# Run all test categories
run_test "test_input.txt" "Basic Functionality Tests"
run_test "test_edge_clean.txt" "Edge Cases & Boundary Testing"
run_test "test_stress_mini.txt" "Mini Stress Testing"
run_test "test_memory.txt" "Memory Safety Testing"
run_test "test_final_validation.txt" "Production Validation"

# Optional comprehensive tests (longer running)
echo -e "${YELLOW}🔥 Extended Test Suite:${NC}"
run_test "test_stress.txt" "Full Stress Testing (200+ operations)"
run_test "test_edge_cases.txt" "Comprehensive Edge Cases"

# Calculate results
END_TIME=$(date +%s)
DURATION=$((END_TIME - START_TIME))
TOTAL_TESTS=$((TESTS_PASSED + TESTS_FAILED))

echo "=================================================="
echo -e "${BLUE}📊 Test Results Summary:${NC}"
echo "Total Tests: $TOTAL_TESTS"
echo -e "Passed: ${GREEN}$TESTS_PASSED${NC}"
echo -e "Failed: ${RED}$TESTS_FAILED${NC}"
echo "Duration: ${DURATION}s"
echo ""

if [ $TESTS_FAILED -eq 0 ]; then
    echo -e "${GREEN}🎉 All tests passed! Your implementation is solid.${NC}"
    exit 0
else
    echo -e "${RED}⚠️  Some tests failed. Please review the implementation.${NC}"
    exit 1
fi
