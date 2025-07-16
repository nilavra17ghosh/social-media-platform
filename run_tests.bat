@echo off
REM Social Media Platform Test Runner for Windows
REM This script runs all test cases and provides a summary

echo Social Media Platform - Comprehensive Test Suite
echo ==================================================
echo.

set TESTS_PASSED=0
set TESTS_FAILED=0

REM Check if executable exists
if not exist "social_media.exe" (
    echo social_media.exe not found. Please compile first:
    echo gcc -Wall -Wextra -std=c99 -g -o social_media code/main.c code/comment.c code/platform.c code/post.c code/reply.c
    exit /b 1
)

echo Test Categories:
echo 1. Basic Functionality Tests
echo 2. Edge Cases and Boundary Testing
echo 3. Stress Testing
echo 4. Memory Safety Testing
echo 5. Production Validation
echo.

REM Run tests
call :run_test "test_input.txt" "Basic_Functionality_Tests"
call :run_test "test_edge_clean.txt" "Edge_Cases_Testing"
call :run_test "test_stress_mini.txt" "Mini_Stress_Testing"
call :run_test "test_memory.txt" "Memory_Safety_Testing"
call :run_test "test_final_validation.txt" "Production_Validation"

echo Extended Test Suite:
call :run_test "test_stress.txt" "Full_Stress_Testing"

set /a TOTAL_TESTS=%TESTS_PASSED%+%TESTS_FAILED%

echo ==================================================
echo Test Results Summary:
echo Total Tests: %TOTAL_TESTS%
echo Passed: %TESTS_PASSED%
echo Failed: %TESTS_FAILED%
echo.

if %TESTS_FAILED% equ 0 (
    echo All tests passed! Your implementation is solid.
    exit /b 0
) else (
    echo Some tests failed. Please review the implementation.
    exit /b 1
)

:run_test
set test_file=%~1
set test_name=%~2

echo Running %test_name%...

if exist "tests\%test_file%" (
    powershell -Command "Get-Content tests\%test_file% | .\social_media.exe" >nul 2>&1
    if errorlevel 1 (
        echo %test_name% FAILED
        set /a TESTS_FAILED+=1
    ) else (
        echo %test_name% PASSED
        set /a TESTS_PASSED+=1
    )
) else (
    echo Test file tests\%test_file% not found
    set /a TESTS_FAILED+=1
)
echo.
goto :eof
