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
// gcc -o test.exe libft.a test/test.c

#include <ctype.h>
#include <stdio.h>
#include <assert.h> 
#include <stddef.h>

#include "libft.h"
#include "test_part_2.c"

static char		ft_test_for_ft_strmapi(unsigned int i, char c)
{
	c = c + i;
	return (c);
}

static void 	ft_print_lst(t_list *n) 
{
	if (n == NULL)
		printf("Node was NULL\n");
	while (n != NULL)
	{ 
		printf("%s\n", n->content); 
		n = n->next; 
	}
}

static void		ft_delnode_content(void *n)
{
	n = NULL;
}

static void		*ft_change_node_content(void *n)
{
	unsigned int	len;
	unsigned int	i;

	i = 0;
	len = ft_strlen(n);
	if (len)
	{
		while (i < len)
		{
			// (char)n[i] += 1;
			((char *)n)[i] += 1;
			i++;
		}
	}
	return (0);
}

static void		*ft_mapelem(char *content)
{
	int		i;

	i = 0;

	while (content[i])
	{
		content[i] = 'y';
		i++;
	}
	return (content);
}

int		main(void)
{
// ----------------------------------------------------- //
// ----------------------------------------------------- //
// ----------------------------------------------------- //
				// PART 1 TESTS //
// ----------------------------------------------------- //
// ----------------------------------------------------- //
// ----------------------------------------------------- //


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
	// Test 1
	char memcpy_src[15] = "Hello there!";
	char memcpy_dst[15] = "xxxxxxxxxxxx";

	char ft_memcpy_src[15] = "Hello there!";
	char ft_memcpy_dst[15] = "xxxxxxxxxxxx";

	char* memcpy_result = memcpy(memcpy_dst, memcpy_src, 12);
    char* ft_memcpy_result = ft_memcpy(ft_memcpy_dst, ft_memcpy_src, 12);

    assert(memcpy_result[0] == ft_memcpy_result[0]);
	
	// printf("%s\n", ft_memcpy_result);
	// printf("%s\n", memcpy_result);

	// Test 2 (Inputs are NULL)
	char memcpy_src2[5] = "NULL";
	char memcpy_dst2[5] = "NULL";

	char ft_memcpy_src2[5] = "NULL";
	char ft_memcpy_dst2[5] = "NULL";

	char* memcpy_result2 = memcpy(memcpy_dst2, memcpy_src2, 5);
    char* ft_memcpy_result2 = ft_memcpy(ft_memcpy_dst2, ft_memcpy_src2, 5);

    // assert(memcpy_result2 == ft_memcpy_result2);

	printf("%s\n", ft_memcpy_result2);
	printf("%s\n", memcpy_result2);


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
    // Tests for ft_memmove

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
    // Test for ft_strchr

	char strchr_src[15] = "Hello there!";
	char ft_strchr_src[15] = "Hello there!";

	charToFind = 'o';

	char* strchr_result = strchr(strchr_src, charToFind);
    char* ft_strchr_result = ft_strchr(ft_strchr_src, charToFind);

	counter = 0;
	while (counter < 7)
	{
		assert(strchr_result[counter] == ft_strchr_result[counter]);
		counter++;
	}

	// printf("%s\n", ft_strchr_result);
	// printf("%s\n", strchr_result);
	

// ----------------------------------------------------- //
    // Tests for ft_strrchr

	char strrchr_src[15] = "Hello there!";
	char ft_strrchr_src[15] = "Hello there!";

	charToFind = 'e';

	char* strrchr_result = strrchr(strrchr_src, charToFind);
    char* ft_strrchr_result = ft_strrchr(ft_strrchr_src, charToFind);

	counter = 0;
	while (counter < 2)
	{
		assert(strrchr_result[counter] == ft_strrchr_result[counter]);
		counter++;
	}

	// printf("%s\n", ft_strrchr_result);
	// printf("%s\n", strrchr_result);
	


// ----------------------------------------------------- //
	// Tests for ft_strnstr

	char strnstr_src[15] = "Hello there!";
	char ft_strnstr_src[15] = "Hello there!";

	char* strnstr_result = strnstr(strnstr_src, "there", 12);
    char* ft_strnstr_result = ft_strnstr(ft_strnstr_src, "there", 12);

	counter = 0;
	while (counter < 6)
	{
		assert(strnstr_result[counter] == ft_strnstr_result[counter]);
		counter++;
	}

	// printf("%s\n", ft_strnstr_result);
	// printf("%s\n", strnstr_result);
	

	// Test 2 (should not work as len stops before "to" is fully found)
	char strnstr_src2[20] = "Hello to all";
	char ft_strnstr_src2[20] = "Hello to all";

	char* strnstr_result2 = strnstr(strnstr_src2, "to", 7);
    char* ft_strnstr_result2 = ft_strnstr(ft_strnstr_src2, "to", 7);

	assert(strnstr_src2[0] == ft_strnstr_src2[0]);

	// printf("%s\n", ft_strnstr_result2);
	// printf("%s\n", strnstr_result2);


	// Test 3 
	char strnstr_src3[20] = "Hello to all";
	char ft_strnstr_src3[20] = "Hello to all";

	char* strnstr_result3 = strnstr(strnstr_src2, "", 7);
    char* ft_strnstr_result3 = ft_strnstr(ft_strnstr_src2, "", 7);

	counter = 0;
	while (counter < 13)
	{
		assert(strnstr_result3[counter] == ft_strnstr_result3[counter]);
		counter++;
	}

	// printf("%s\n", ft_strnstr_result3);
	// printf("%s\n", strnstr_result3);

// ----------------------------------------------------- //
	// Tests for ft_strlcat

	// Test 1
	char strlcat_src[15] = "there!";
	char strlcat_dst[15] = "Hello ";

	char ft_strlcat_src[15] = "there!";
	char ft_strlcat_dst[15] = "Hello ";
	
	size_t strlcat_result = strlcat(strlcat_dst, strlcat_src, 13);
    size_t ft_strlcat_result = ft_strlcat(ft_strlcat_dst, ft_strlcat_src, 13);

	assert(strlcat_result == ft_strlcat_result);

	// printf("%zu\n", strlcat_result);
	// printf("%zu\n", ft_strlcat_result);

	// Test 2
	char strlcat_src2[15] = "bob";
	char strlcat_dst2[15] = "cat";

	char ft_strlcat_src2[15] = "bob";
	char ft_strlcat_dst2[15] = "cat";

	size_t strlcat_result2 = strlcat(strlcat_dst2, strlcat_src2, 0);
    size_t ft_strlcat_result2 = ft_strlcat(ft_strlcat_dst2, ft_strlcat_src2, 0);
	
	assert(strlcat_result2 == ft_strlcat_result2);

	// Test 3
	char strlcat_src3[15] = "a";
	char strlcat_dst3[30] = "lorem ipsum dolor sit amet";

	char ft_strlcat_src3[15] = "a";
	char ft_strlcat_dst3[30] = "lorem ipsum dolor sit amet";

	size_t strlcat_result3 = strlcat(strlcat_dst3, strlcat_src3, 0);
	size_t ft_strlcat_result3 = ft_strlcat(ft_strlcat_dst3, ft_strlcat_src3, 0);

	// printf("%zu\n", strlcat_result3);
	// printf("%zu\n", ft_strlcat_result3);

	assert(strlcat_result3 == ft_strlcat_result3);

// ----------------------------------------------------- //
	// Tests for ft_strlcpy

	// Test 1
	char strlcpy_src[15] = "source";
	char strlcpy_dst[15] = "destination";

	char ft_strlcpy_src[15] = "source";
	char ft_strlcpy_dst[15] = "destination";
	
	size_t strlcpy_result = strlcpy(strlcpy_dst, strlcpy_src, 6);
    size_t ft_strlcpy_result = ft_strlcpy(ft_strlcpy_dst, ft_strlcpy_src, 6);

	assert(strlcpy_result == ft_strlcpy_result);

	// printf("%zu\n", strlcpy_result);
	// printf("%zu\n", ft_strlcpy_result);

	// Test 2 (dstsize = 0)
	char strlcpy_src2[15] = "source";
	char strlcpy_dst2[15] = "destination";

	char ft_strlcpy_src2[15] = "source";
	char ft_strlcpy_dst2[15] = "destination";
	
	size_t strlcpy_result2 = strlcpy(strlcpy_dst2, strlcpy_src2, 0);
    size_t ft_strlcpy_result2 = ft_strlcpy(ft_strlcpy_dst2, ft_strlcpy_src2, 0);

	assert(strlcpy_result2 == ft_strlcpy_result2);

	// printf("%zu\n", strlcpy_result2);
	// printf("%zu\n", ft_strlcpy_result2);

	// Test 3 (dstsize > src size)
	char strlcpy_src3[15] = "source";
	char strlcpy_dst3[15] = "destination";

	char ft_strlcpy_src3[15] = "source";
	char ft_strlcpy_dst3[15] = "destination";
	
	size_t strlcpy_result3 = strlcpy(strlcpy_dst3, strlcpy_src3, 10);
    size_t ft_strlcpy_result3 = ft_strlcpy(ft_strlcpy_dst2, ft_strlcpy_src2, 10);

	assert(strlcpy_result3 == ft_strlcpy_result3);

	// printf("%zu\n", strlcpy_result3);
	// printf("%zu\n", ft_strlcpy_result3);

	// Test 4 (dstsize < src length)
	char strlcpy_src4[15] = "source";
	char strlcpy_dst4[15] = "destination";

	char ft_strlcpy_src4[15] = "source";
	char ft_strlcpy_dst4[15] = "destination";
	
	size_t strlcpy_result4 = strlcpy(strlcpy_dst4, strlcpy_src4, 3);
    size_t ft_strlcpy_result4 = ft_strlcpy(ft_strlcpy_dst4, ft_strlcpy_src4, 3);

	assert(strlcpy_result4 == ft_strlcpy_result4);

	// printf("%zu\n", strlcpy_result4);
	// printf("%zu\n", ft_strlcpy_result4);





// ----------------------------------------------------- //
// ----------------------------------------------------- //
// ----------------------------------------------------- //
				// PART 2 TESTS //
// ----------------------------------------------------- //
// ----------------------------------------------------- //
// ----------------------------------------------------- //

// ----------------------------------------------------- //
	// Tests for ft_substr
	// Test 1
	char const ft_substr_input[15] = "destination";
	char ft_substr_output[15] = "nation";

    char *ft_substr_result = ft_substr(ft_substr_input, 5, 7);
	
	counter = 0;
	while (counter < 7)
	{
		assert(ft_substr_result[counter] == ft_substr_output[counter]);
		counter++;
	}
	
	// printf("%s\n", ft_substr_result);

	// Test 2
	char const ft_substr_input2[15] = "destination";
	char ft_substr_output2[5] = "";

    char *ft_substr_result2 = ft_substr(ft_substr_input2, 5, 0);
	
	counter = 0;
	while (counter < 1)
	{
		assert(ft_substr_result2[counter] == ft_substr_output2[counter]);
		counter++;
	}
	// printf("%s\n", ft_substr_result2);

	// Test 3
	char const ft_substr_input3[15] = "destination";
	char ft_substr_output3[15] = "destinatio";

    char *ft_substr_result3 = ft_substr(ft_substr_input3, 0, 10);
	
	counter = 0;
	while (counter < 10)
	{
		assert(ft_substr_result3[counter] == ft_substr_output3[counter]);
		counter++;
	}	
	// printf("%s\n", ft_substr_result3);

	// Test 4
	char const ft_substr_input4[1] = "";
	char ft_substr_output4[1] = "";

    char *ft_substr_result4 = ft_substr(ft_substr_input4, 0, 10);
	
	counter = 0;
	while (counter < 1)
	{
		assert(ft_substr_result4[counter] == ft_substr_output4[counter]);
		counter++;
	}	
	// printf("%s\n", ft_substr_result4);

// ----------------------------------------------------- //
	// Tests for ft_strjoin
	// Test 1
	char const ft_strjoin_input1[15] = "12345";
	char const ft_strjoin_input2[15] = "67890";
	char const ft_strjoin_expected[15] = "1234567890";

    char *ft_strjoin_result = ft_strjoin(ft_strjoin_input1, ft_strjoin_input2);
	
	counter = 0;
	while (counter < 10)
	{
		assert(ft_strjoin_result[counter] == ft_strjoin_expected[counter]);
		counter++;
	}
	// printf("%s\n", ft_strjoin_expected);
	// printf("%s\n", ft_strjoin_result);
	
	// Test 2
	char const ft_strjoin_input3[15] = "123";
	char const ft_strjoin_input4[15] = "67890abc";
	char const ft_strjoin_expected2[15] = "12367890abc";

    char *ft_strjoin_result2 = ft_strjoin(ft_strjoin_input3, ft_strjoin_input4);
	
	counter = 0;
	while (counter < 11)
	{
		assert(ft_strjoin_result2[counter] == ft_strjoin_expected2[counter]);
		counter++;
	}
	// printf("%s\n", ft_strjoin_expected2);
	// printf("%s\n", ft_strjoin_result2);
	
	
// ----------------------------------------------------- //
	// Tests for ft_strtrim
	// Test 1
	char const ft_strtrim_input1[9] = "  12345  ";
	char const ft_strtrim_input2[5] = " .,\n";
	char const ft_strtrim_expected[6] = "12345";

    char *ft_strtrim_result = ft_strtrim(ft_strtrim_input1, ft_strtrim_input2);
	
	counter = 0;
	while (counter < 5)
	{
		assert(ft_strtrim_result[counter] == ft_strtrim_expected[counter]);
		counter++;
	}

	// printf("%s\n", ft_strtrim_result);
	// printf("%zu\n", ft_strlen(ft_strtrim_result));
	// printf("%s\n", ft_strtrim_expected);

	assert(ft_strtrim_result[0] == ft_strtrim_expected[0]);

// ----------------------------------------------------- //
	// Tests for ft_split
	// Test 1

    char **ft_split_result = ft_split("Hello there friend!", ' ');
	char *ft_split_expected1 = "Hello";

	counter = 0;
	while (counter < 5)
	{
		assert(ft_split_result[0][counter] == ft_split_expected1[counter]);
		// printf("%c\n", ft_split_result[0][counter]);
		counter++;
	}
	
	// Test 2
	char **ft_split_result2 = ft_split("          ", ' ');
	// assert(!ft_split_result2[0][0]);
	// printf("Result is: %s\n", ft_split_result2[0]);
	

	// Test 3
	char **ft_split_result3 = ft_split("lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed non risus. Suspendisse", ' ');

	assert(strcmp(ft_split_result3[0], "lorem") == 0);
	assert(strcmp(ft_split_result3[1], "ipsum") == 0);
	assert(strcmp(ft_split_result3[2], "dolor") == 0);
	assert(strcmp(ft_split_result3[3], "sit") == 0);
	assert(strcmp(ft_split_result3[4], "amet,") == 0);
	assert(strcmp(ft_split_result3[5], "consectetur") == 0);
	assert(strcmp(ft_split_result3[6], "adipiscing") == 0);
	assert(strcmp(ft_split_result3[7], "elit.") == 0);
	assert(strcmp(ft_split_result3[8], "Sed") == 0);
	assert(strcmp(ft_split_result3[9], "non") == 0);
	assert(strcmp(ft_split_result3[10], "risus.") == 0);
	assert(strcmp(ft_split_result3[11], "Suspendisse") == 0);

	// Test 4 (with ample spaces)
	char **ft_split_result4 = ft_split("   lorem   ipsum dolor     sit amet, consectetur   adipiscing elit. Sed non risus. Suspendisse   ", ' ');

	assert(strcmp(ft_split_result4[0], "lorem") == 0);
	assert(strcmp(ft_split_result4[1], "ipsum") == 0);
	assert(strcmp(ft_split_result4[2], "dolor") == 0);
	assert(strcmp(ft_split_result4[3], "sit") == 0);
	assert(strcmp(ft_split_result4[4], "amet,") == 0);
	assert(strcmp(ft_split_result4[5], "consectetur") == 0);
	assert(strcmp(ft_split_result4[6], "adipiscing") == 0);
	assert(strcmp(ft_split_result4[7], "elit.") == 0);
	assert(strcmp(ft_split_result4[8], "Sed") == 0);
	assert(strcmp(ft_split_result4[9], "non") == 0);
	assert(strcmp(ft_split_result4[10], "risus.") == 0);
	assert(strcmp(ft_split_result4[11], "Suspendisse") == 0);



// ----------------------------------------------------- //
	// Tests for ft_itoa

    char *ft_itoa_result = ft_itoa(12345);
	char *ft_itoa_result2 = ft_itoa(-1);
	char *ft_itoa_result3 = ft_itoa(1);
	char *ft_itoa_result4 = ft_itoa(10000000);
	char *ft_itoa_result5 = ft_itoa(-10000000);
	char *ft_itoa_result6 = ft_itoa(0);
	char *ft_itoa_result7 = ft_itoa(-2147483648LL);

	assert(0 == ft_strncmp(ft_itoa_result, "12345", 6));
	assert(0 == ft_strncmp(ft_itoa_result2, "-1", 2));
	assert(0 == ft_strncmp(ft_itoa_result3, "1", 1));
	assert(0 == ft_strncmp(ft_itoa_result4, "10000000", 9));
	assert(0 == ft_strncmp(ft_itoa_result5, "-10000000", 10));
	assert(0 == ft_strncmp(ft_itoa_result6, "0", 1));
	assert(0 == ft_strncmp(ft_itoa_result7, "-2147483648LL", 11));


	// printf("%s\n", ft_itoa_result);
	// printf("%s\n", ft_itoa_result2);
	// printf("%s\n", ft_itoa_result3);
	// printf("%s\n", ft_itoa_result4);
	// printf("%s\n", ft_itoa_result5);
	// printf("%s\n", ft_itoa_result6);



// ----------------------------------------------------- //
	// Tests for ft_strmapi

	// static unsigned int		ft_test_for_ft_strmapi(unsigned int i, char c)
	// {
	// 	c = c + i;
	// 	return (c);
	// }

	char *ft_strmapi_result = ft_strmapi("hello", ft_test_for_ft_strmapi);
	// printf("%s\n", ft_strmapi_result);
	assert(0 == ft_strncmp(ft_strmapi_result, "hfnos", 5));



// ----------------------------------------------------- //
	// Tests for ft_putchar_fd

	// ft_putchar_fd('c', 1);
	// ft_putchar_fd('3', 1);

// ----------------------------------------------------- //
	// Tests for ft_putstr_fd

	// ft_putstr_fd("Hello there", 1);
	// ft_putstr_fd("Hello there my friend, how are you?", 1);
	// ft_putstr_fd("   Hello there my friend,\n how are \t\tyou?", 1);

// ----------------------------------------------------- //
	// Tests for ft_putendl_fd

	// ft_putendl_fd("Hello there", 1);
	// ft_putendl_fd("Hello there", 2);
	// ft_putendl_fd("", 1);
	// ft_putendl_fd("lorem ipsum dolor sit amet", 1);

// ----------------------------------------------------- //
	// Tests for ft_putnbr_fd

	// ft_putnbr_fd(4, 1);
	// ft_putendl_fd("", 1);

	// ft_putnbr_fd(45, 1);
	// ft_putendl_fd("", 1);

	// ft_putnbr_fd(4000, 1);
	// ft_putendl_fd("", 1);

	// ft_putnbr_fd(-45555, 1);
	// ft_putendl_fd("", 1);

	// ft_putnbr_fd(2147483647, 1);
	// ft_putendl_fd("", 1);

	// ft_putnbr_fd(-2147483648, 1);
	// ft_putendl_fd("", 1);



// ----------------------------------------------------- //
// ----------------------------------------------------- //
// ----------------------------------------------------- //
				// BONUS PART TESTS //
// ----------------------------------------------------- //
// ----------------------------------------------------- //
// ----------------------------------------------------- //

// // ----------------------------------------------------- //
// 	// Tests for ft_lstnew
// 	// Test 1
// 	t_list *ft_lstnew_result = ft_lstnew("I am a new list item!");

// 	assert(ft_lstnew_result->next == NULL);
// 	assert(0 == ft_strncmp(ft_lstnew_result->content, "I am a new list item!", 21));

// 	// printf("%s\n", ft_lstnew_result->content);
	
// 	// Test 2
// 	t_list *ft_lstnew_result2 = ft_lstnew("127t44ioyo34y\n\n\n\t");

// 	assert(ft_lstnew_result2->next == NULL);
// 	assert(0 == ft_strncmp(ft_lstnew_result2->content, "127t44ioyo34y\n\n\n\t", 17));

// 	// Test 3
// 	t_list *ft_lstnew_result3 = ft_lstnew(NULL);

// 	assert(ft_lstnew_result3->next == NULL);
// 	assert(ft_lstnew_result3->content == NULL);

// // ----------------------------------------------------- //
// 	// Tests for ft_lstadd_front

// 	// Make a list to check
// 	t_list **alist;
// 	t_list *new_head = ft_lstnew("0");
// 	t_list *ft_lst_item1 = ft_lstnew("1");
// 	t_list *ft_lst_item2 = ft_lstnew("2");
// 	t_list *ft_lst_item3 = ft_lstnew("3");

// 	ft_lst_item1->next = ft_lst_item2;
// 	ft_lst_item2->next = ft_lst_item3;
// 	alist = &ft_lst_item1;

// 	// printf("Before: \n");
// 	// ft_print_lst(*alist);

// 	ft_lstadd_front(alist, new_head);
// 	// printf("After: \n");
// 	// ft_print_lst(*alist);

// 	assert(0 == ft_strncmp(new_head->content, "0", 1));
// 	assert(0 == ft_strncmp(new_head->next->content, "1", 1));
// 	assert(0 == ft_strncmp(new_head->next->next->content, "2", 1));
// 	assert(0 == ft_strncmp(new_head->next->next->next->content, "3", 1));

// // ----------------------------------------------------- //
// 	// Tests for ft_lstsize
// 	// Test 1
// 	int ft_lstsize_result = ft_lstsize(new_head);
// 	// printf("%d\n", ft_lstsize_result);
// 	assert(ft_lstsize_result == 4);
	
	
// 	// Test 2
// 	t_list *ft_lstsize_input = ft_lstnew("Hello");
// 	int ft_lstsize_result2 = ft_lstsize(ft_lstsize_input);

// 	assert(ft_lstsize_result2 == 1);


// // ----------------------------------------------------- //
// 	// Tests for ft_lstlast
// 	// Test 1
// 	t_list	*ft_lstlast_result = ft_lstlast(new_head);

// 	assert(0 == ft_strncmp(ft_lstlast_result->content, "3", 1));
// 	// printf("%s\n", ft_lstlast_result->content);

// 	// Test 2
// 	t_list *ft_lstlast_input2 = ft_lstnew("");
// 	t_list	*ft_lstlast_result2 = ft_lstlast(ft_lstlast_input2);

// 	assert(0 == ft_strncmp(ft_lstlast_result2->content, "", 1));
// 	// printf("%s\n", ft_lstlast_result2->content);



// // ----------------------------------------------------- //
// 	// Tests for ft_lstadd_back
// 	// Test 1
// 	// Make a list to check
// 	t_list **alist2;
// 	t_list *new_back = ft_lstnew("Back it up");
// 	t_list *ft_lstadd_back_item1 = ft_lstnew("1");
// 	t_list *ft_lstadd_back_item2 = ft_lstnew("2");
// 	t_list *ft_lstadd_back_item3 = ft_lstnew("3");

// 	ft_lstadd_back_item1->next = ft_lstadd_back_item2;
// 	ft_lstadd_back_item2->next = ft_lstadd_back_item3;
// 	alist2 = &ft_lstadd_back_item1;

// 	// printf("Before: \n");
// 	// ft_print_lst(*alist2);

// 	ft_lstadd_back(alist2, new_back);

// 	// printf("After: \n");
// 	// ft_print_lst(*alist2);

// 	assert(0 == ft_strncmp(ft_lstadd_back_item1->content, "1", 1));
// 	assert(0 == ft_strncmp(ft_lstadd_back_item1->next->content, "2", 1));
// 	assert(0 == ft_strncmp(ft_lstadd_back_item1->next->next->content, "3", 1));
// 	assert(0 == ft_strncmp(ft_lstadd_back_item1->next->next->next->content, "Back it up", 10));



// // ----------------------------------------------------- //
// 	// Tests for ft_lstdelone

// 	t_list *ft_lstdelone_item1 = ft_lstnew("1");

// 	// printf("Before: \n");
// 	// ft_print_lst(ft_lstdelone_item1);
// 	// ft_lstdelone(ft_lstdelone_item1, ft_delnode_content);

// 	// printf("After: \n");
// 	// ft_print_lst(ft_lstdelone_item1);
	
// // ----------------------------------------------------- //
// 	// Tests for ft_lstclear
// 	// Test 1

// 	t_list **alist3;
// 	t_list *ft_lstclear_item1 = ft_lstnew("1");
// 	t_list *ft_lstclear_item2 = ft_lstnew("2");
// 	t_list *ft_lstclear_item3 = ft_lstnew("3");

// 	ft_lstclear_item1->next = ft_lstclear_item2;
// 	ft_lstclear_item2->next = ft_lstclear_item3;
// 	alist3 = &ft_lstclear_item1;

// 	// printf("Before: \n");
// 	// ft_print_lst(ft_lstclear_item1);
	
// 	ft_lstclear(alist3, ft_delnode_content); // Seg fault
	
// 	// printf("After: \n");
// 	// ft_print_lst(ft_lstclear_item1);

// 	// assert(ft_lstclear_item1->next == NULL);
// 	// assert(ft_lstclear_item2->next == NULL);
// 	// assert(ft_lstclear_item3->next == NULL);


	
// // ----------------------------------------------------- //
// 	// Tests for ft_lstiter
// 	// Test 1
	// t_list *ft_lstiter_item1 = ft_lstnew("1a");
	// t_list *ft_lstiter_item2 = ft_lstnew("2a");
	// t_list *ft_lstiter_item3 = ft_lstnew("3a");

	// char[10] ft_lstiter_item1_new = "Test 1";
	// char[10] ft_lstiter_item2_new = "Test 2";
	// char[10] ft_lstiter_item3_new = "Test 3";

	// ft_lstiter_item1->next = ft_lstiter_item2;
	// ft_lstiter_item2->next = ft_lstiter_item3;

	// printf("Before: \n");
	// ft_print_lst(ft_lstiter_item1);

	// // ft_lstiter(ft_lstiter_item1, ft_change_node_content);

	// printf("After: \n");
	// ft_print_lst(ft_lstiter_item1);


// ----------------------------------------------------- //
	// Tests for ft_lstmap
	// Test 1
	t_list *ft_lstmap_item1 = ft_lstnew("111");
	// t_list *ft_lstmap_item2 = ft_lstnew("222");
	// t_list *ft_lstmap_item3 = ft_lstnew("333");

	// char[10] ft_lstmap_item1_new = "Test 1";
	// char[10] ft_lstmap_item2_new = "Test 2";
	// char[10] ft_lstmap_item2_new = "Test 3";

	// ft_lstmap_item1->next = ft_lstmap_item2;
	// ft_lstmap_item2->next = ft_lstmap_item3;

	// printf("Before: \n");
	// ft_print_lst(ft_lstmap_item1);

	// Want to change the char by +1 for each in the string
	ft_lstmap(ft_lstmap_item1, (void *)&ft_mapelem, (void *)&ft_delnode_content);

	// printf("After: \n");
	// ft_print_lst(ft_lstmap_item1);






	return (0);
}
