/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akowalsk <akowalsk@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 19:02:02 by akowalsk          #+#    #+#             */
/*   Updated: 2020/11/05 19:02:05 by akowalsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


// Run below commmand to compile this test file with the libft.a library
// gcc -o test.exe libft.a test.c

#include <ctype.h>
#include <stdio.h>
#include "libft.h"
#include <assert.h> 

int		main(void)
{
// ----------------------------------------------------- //
	// Tests for ft_strlen

	size_t ft_len_test;
	size_t len_test;

	ft_len_test = ft_strlen("shalom");
	len_test = strlen("shalom");

	assert(ft_len_test == len_test);

// ----------------------------------------------------- //
	// Tests for ft_strncmp

    const char *ft_strncmp_string1 = "Hello World!";
    const char *ft_strncmp_string2 = "Hello World.";

    int strncmp_result = strncmp(ft_strncmp_string1, ft_strncmp_string2, 12);
    int ft_strncmp_result = ft_strncmp(ft_strncmp_string1, ft_strncmp_string2, 12);

    assert(strncmp_result == ft_strncmp_result);

    const char *ft_strncmp_string3 = "!";
    const char *ft_strncmp_string4 = " ";

    int strncmp_result2 = strncmp(ft_strncmp_string3, ft_strncmp_string4, 1);
    int ft_strncmp_result2 = ft_strncmp(ft_strncmp_string3, ft_strncmp_string4, 1);

    assert(strncmp_result2 == ft_strncmp_result2);

    const char *ft_strncmp_string5 = "Kol";
    const char *ft_strncmp_string6 = "Kool";

    int strncmp_result3 = strncmp(ft_strncmp_string5, ft_strncmp_string6, 3);
    int ft_strncmp_result3 = ft_strncmp(ft_strncmp_string5, ft_strncmp_string6, 3);

    assert(strncmp_result3 == ft_strncmp_result3);


// ----------------------------------------------------- //
	// Tests for ft_atoi

	const char *atoi_str;
	atoi_str = "-496";

	assert(ft_atoi(atoi_str) == atoi(atoi_str));

	const char *atoi_str2;
	atoi_str2 = "2147483647";

	assert(ft_atoi(atoi_str2) == atoi(atoi_str2));

	const char *atoi_str3;
	atoi_str3 = "-2147483648";

	assert(ft_atoi(atoi_str3) == atoi(atoi_str3));

// ----------------------------------------------------- //
	// Tests for ft_toupper

	int input_ft_toupper = 'd';
	int input_ft_toupper2 = 'h';
	int input_ft_toupper3 = 'b';

	assert(ft_toupper(input_ft_toupper) == toupper(input_ft_toupper));
	assert(ft_toupper(input_ft_toupper2) == toupper(input_ft_toupper2));
	assert(ft_toupper(input_ft_toupper3) == toupper(input_ft_toupper3));

// ----------------------------------------------------- //
	// Tests for ft_tolower

	int input_ft_tolower = 'D';
	int input_ft_tolower2 = 'H';
	int input_ft_tolower3 = 'B';

	assert(ft_tolower(input_ft_tolower) == tolower(input_ft_tolower));
	assert(ft_tolower(input_ft_tolower2) == tolower(input_ft_tolower2));
	assert(ft_tolower(input_ft_tolower3) == tolower(input_ft_tolower3));


// ----------------------------------------------------- //
	// Tests for ft_isalpha

	int input_ft_isalpha = 'Z';
	int input_ft_isalpha2 = 'p';
	int input_ft_isalpha3 = '9';

	assert(ft_isalpha(input_ft_isalpha) == isalpha(input_ft_isalpha));
	assert(ft_isalpha(input_ft_isalpha2) == isalpha(input_ft_isalpha2));
	assert(ft_isalpha(input_ft_isalpha3) == isalpha(input_ft_isalpha3));

// ----------------------------------------------------- //
	// Tests for ft_isdigit

	int input_ft_isdigit = '4';
	int input_ft_isdigit2 = -9;
	int input_ft_isdigit3 = 'a';

	assert(ft_isdigit(input_ft_isdigit) == isdigit(input_ft_isdigit));
	assert(ft_isdigit(input_ft_isdigit2) == isdigit(input_ft_isdigit2));
	assert(ft_isdigit(input_ft_isdigit3) == isdigit(input_ft_isdigit3));

	// printf("%i\n", ft_isdigit(input_ft_isdigit));
	// printf("%i\n", isdigit(input_ft_isdigit));
// ----------------------------------------------------- //
	// Tests for ft_isalnum

	int input_ft_isalnum = 'Z';
	int input_ft_isalnum2 = '5';
	int input_ft_isalnum3 = '\'';

	assert(ft_isalnum(input_ft_isdigit) == isalnum(input_ft_isdigit));
	assert(ft_isalnum(input_ft_isdigit2) == isalnum(input_ft_isdigit2));
	assert(ft_isalnum(input_ft_isdigit3) == isalnum(input_ft_isdigit3));

// ----------------------------------------------------- //
	// Tests for ft_isascii

	int input_ft_isascii = 'Z';
	int input_ft_isascii2 = '5';
	int input_ft_isascii3 = '\'';

	assert(ft_isascii(input_ft_isascii) == isascii(input_ft_isascii));
	assert(ft_isascii(input_ft_isascii2) == isascii(input_ft_isascii2));
	assert(ft_isascii(input_ft_isascii3) == isascii(input_ft_isascii3));

// ----------------------------------------------------- //
	// Tests for ft_isprint

	int input_ft_isprint = 'Z';
	int input_ft_isprint2 = ' ' ;
	int input_ft_isprint3 = '\'';

	assert(ft_isprint(input_ft_isprint) == isprint(input_ft_isprint));
	assert(ft_isprint(input_ft_isprint2) == isprint(input_ft_isprint2));
	assert(ft_isprint(input_ft_isprint3) == isprint(input_ft_isprint3));

// ----------------------------------------------------- //
	// Tests for ft_strndup

	char *input_ft_strdup = "I am a string..";
	char *res_ft_strdup = ft_strdup(input_ft_strdup);
	char *res_strdup = strdup(input_ft_strdup);

	int counter = 0;
	while (counter < 15)
	{
		assert(res_ft_strdup[counter] == res_strdup[counter]);
		counter++;
	}

// ----------------------------------------------------- //
	// Tests for ft_memset

	char input_ft_memset[100] = "I pledge allegiance to the flag of the United Mars Alliance.";
	char input_memset[100] = "I pledge allegiance to the flag of the United Mars Alliance.";

	// Add .'s after the first I 8 times
	ft_memset(input_ft_memset + 1, '.', 8 * sizeof(char));
	memset(input_memset + 1, '.', 8 * sizeof(char));

	int len_memset = ft_strlen(input_ft_memset);
	counter = 0;
	while (counter < len_memset)
	{
		assert(input_ft_memset[counter] == input_memset[counter]);
		counter++;
	}
	// printf("%s\n", input_ft_memset);
	// printf("%s\n", input_memset);

// ----------------------------------------------------- //
    // Test for ft_bzero
	char input_ft_bzero[15] = "Hello there!";
	char input_bzero[15] = "Hello there!";

	int len_bzero = ft_strlen(input_ft_bzero);

	ft_bzero(input_ft_bzero, 5);
	bzero(input_bzero, 5);

	counter = 0;
	while (counter < len_bzero)
	{
		assert(input_ft_bzero[counter] == input_bzero[counter]);
		counter++;
	}
	// printf("%s\n", input_ft_bzero);
	// printf("%s\n", input_bzero);

// ----------------------------------------------------- //
    // Test for ft_memcpy
	char memcpy_src[15] = "Hello there!";
	char memcpy_dst[15] = "xxxxxxxxxxxx";

	char ft_memcpy_src[15] = "Hello there!";
	char ft_memcpy_dst[15] = "xxxxxxxxxxxx";

	char* memcpy_result = memcpy(memcpy_dst, memcpy_src, 12);
    char* ft_memcpy_result = ft_memcpy(ft_memcpy_dst, ft_memcpy_src, 12);

    assert(memcpy_result[0] == ft_memcpy_result[0]);
	
	// printf("%s\n", ft_memcpy_result);
	// printf("%s\n", memcpy_result);



// ----------------------------------------------------- //
    // Test for ft_memccpy
	// Test 1 (return xx)
	char memccpy_src[15] = "Hello there!";
	char memccpy_dst[15] = "xxxxxxxxxxxx";

	char ft_memccpy_src[15] = "Hello there!";
	char ft_memccpy_dst[15] = "xxxxxxxxxxxx";

	int charToFind = 'r';

	char* memccpy_result = memccpy(memccpy_dst, memccpy_src, charToFind, 12);
    char* ft_memccpy_result = ft_memccpy(ft_memccpy_dst, ft_memccpy_src, charToFind, 12);

	counter = 0;
	while (counter < 2)
	{
		assert(memccpy_result[counter] == ft_memccpy_result[counter]);
		counter++;
	}
    
	// Test 2 (return NULL pointer)
	char memccpy_src2[15] = "Hello there!";
	char memccpy_dst2[15] = "xxxxxxxxxxxx";

	char ft_memccpy_src2[15] = "Hello there!";
	char ft_memccpy_dst2[15] = "xxxxxxxxxxxx";

	int charToFind2 = 'K';

	char* memccpy_result2 = memccpy(memccpy_dst2, memccpy_src2, charToFind2, 3);
    char* ft_memccpy_result2 = ft_memccpy(ft_memccpy_dst2, ft_memccpy_src2, charToFind2, 3);
	
	assert(memccpy_result2 == ft_memccpy_result2);
	// printf("%s\n", ft_memccpy_result);
	// printf("%s\n", memccpy_result);

// ----------------------------------------------------- //
	// Test for ft_memchr
	// Test 1 (finds c and return a pointer to c)
	char memchr_src[15] = "Hello there!";

	char ft_memchr_src[15] = "Hello there!";

	charToFind = 'o';

	char* memchr_result = memchr(memchr_src, charToFind, 12);
    char* ft_memchr_result = ft_memchr(ft_memchr_src, charToFind, 12);

	counter = 0;
	while (counter < 7)
	{
		assert(memchr_result[counter] == ft_memchr_result[counter]);
		counter++;
	}

	// printf("%s\n", ft_memchr_result);
	// printf("%s\n", memchr_result);

	// Test 2 (Does not find c and returns a NULL pointer)
	char memchr_src2[15] = "Hello there!";

	char ft_memchr_src2[15] = "Hello there!";

	charToFind = 'J';

	char* memchr_result2 = memchr(memchr_src2, charToFind, 12);
    char* ft_memchr_result2 = ft_memchr(ft_memchr_src2, charToFind, 12);
	
	assert(memchr_result2 == ft_memchr_result2);

	// printf("%s\n", ft_memchr_result2);
	// printf("%s\n", memchr_result2);


	// Test 3 (finds c and return a pointer to c)
	char memchr_src3[5] = {3, -5, 10, -10, 210};

	char ft_memchr_src3[5] = {3, -5, 10, -10, 210};

	int intToFind = -10;

	char* memchr_result3 = memchr(memchr_src3, intToFind, 5);
    char* ft_memchr_result3 = ft_memchr(ft_memchr_src3, intToFind, 5);
	
	assert(memchr_result3[0] == ft_memchr_result3[0]);

	// printf("%c\n", ft_memchr_result3[1]);
	// printf("%c\n", memchr_result3[1]);

// ----------------------------------------------------- //
    // Test for ft_memmove
	char str_memmove_src[15] = "Hello there!";
	char str_memmove_dst[15] = "xxxxxxxxxxxx";

	assert(ft_memmove(str_memmove_dst, str_memmove_src, 5) == memmove(str_memmove_dst, str_memmove_src, 5));

	char str_memmove_src2[15] = "Hello";
	char str_memmove_dst2[15] = "xxxxxxxxxxxx";

	assert(ft_memmove(str_memmove_dst2, str_memmove_src2, 12) == memmove(str_memmove_dst2, str_memmove_src2, 12));


// ----------------------------------------------------- //
    // Test for ft_memcmp
	// Test 1 (return -13)
    const char *ft_memcmp_str1 = "Hello World!";
    const char *ft_memcmp_str2 = "Hello World.";

    int memcmp_result = memcmp(ft_memcmp_str1, ft_memcmp_str2, 12);
    int ft_memcmp_result = ft_memcmp(ft_memcmp_str1, ft_memcmp_str2, 12);

    assert(memcmp_result == ft_memcmp_result);

	// printf("%i\n", memcmp_result);
	// printf("%i\n", ft_memcmp_result);


	// Test 2 (return -32)
	const char *ft_memcmp_str3 = "A";
    const char *ft_memcmp_str4 = "abc";

    int memcmp_result2 = memcmp(ft_memcmp_str3, ft_memcmp_str4, 12);
    int ft_memcmp_result2 = ft_memcmp(ft_memcmp_str3, ft_memcmp_str4, 12);

    assert(memcmp_result2 == ft_memcmp_result2);

	// printf("%i\n", memcmp_result2);
	// printf("%i\n", ft_memcmp_result2);


	// Test 3 (return 0)
	const char *ft_memcmp_str5 = "1234ABC";
    const char *ft_memcmp_str6 = "1234ABC";

    int memcmp_result3 = memcmp(ft_memcmp_str5, ft_memcmp_str6, 7);
    int ft_memcmp_result3 = ft_memcmp(ft_memcmp_str5, ft_memcmp_str6, 7);

    assert(memcmp_result3 == ft_memcmp_result3);

	// Test 4 (return 0)
    int memcmp_result4 = memcmp("abcdefghij", "abcdefgxyz", 7);
    int ft_memcmp_result4 = ft_memcmp("abcdefghij", "abcdefgxyz", 7);
	
	assert(memcmp_result4 == ft_memcmp_result4);
	// printf("%i\n", memcmp_result4);
	// printf("%i\n", ft_memcmp_result4);
// ----------------------------------------------------- //
	



//     // TESTS FOR ADDITIONAL FUNCTIONS // 
//         // TESTS FOR ADDITIONAL FUNCTIONS // 
//     		    // TESTS FOR ADDITIONAL FUNCTIONS // 
//         // TESTS FOR ADDITIONAL FUNCTIONS // 
//     // TESTS FOR ADDITIONAL FUNCTIONS // 

//     // Test for ft_putchar
//  //    char input_ft_putchar;
// 	// input_ft_putchar = '4';

// 	// printf("\nTest for ft_putchar: \n\tft_putchar(\'4\') = \n");
// 	// ft_putchar(input_ft_putchar);
// 	// ft_putchar('\n');


	return (0);
}
