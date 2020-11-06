// Run below commmand to compile this test file with the libft.a library
// gcc -o test.exe libft.a test.c

#include <ctype.h>
#include <stdio.h>
#include "libft.h"
#include <assert.h> 

// Part 1 prototypes
size_t	ft_strlen(const char *str);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_atoi(const char *str);
int		ft_toupper(int c);
int		ft_tolower(int c);
int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
char	*ft_strndup(char *src, size_t n);
void	*ft_memset(void *ptr, int c, size_t len);
void	ft_bzero(void *str, size_t n);
void	*ft_memcpy(void *restrict dst, const void *restrict src, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t len);

// void	*calloc(size_t count, size_t size);

// Additional Functions prototypes
void	ft_putchar(char c) {
	write(1, &c, 1);
}
void	ft_putnbr(int nb);

int		main(void)
{
	// Test for ft_strlen
	size_t ft_len_test;
	size_t len_test;
	ft_len_test = ft_strlen("shalom");
	len_test = strlen("shalom");

	assert(ft_len_test == len_test);


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

	// assert(ft_strncmp("a", "z", 1) == strncmp("a", "z", 1));
	printf("%d\n", ft_strncmp("a", "z", 1));
	printf("%d\n", strncmp("a", "z", 1));


// 	// Test for ft_atoi
// 	const char *str;
// 	int res_ft_atoi;
// 	str = "-496";

// 	res_ft_atoi = ft_atoi(str);
// 	printf("\nTest for ft_atoi: \n\tft_atoi(\"-496\") = %d\n", res_ft_atoi);
// 	printf("\tatoi(\"-496\") = %d\n", atoi(str));	

// 	// Test for ft_toupper
// 	int input_ft_toupper;
// 	input_ft_toupper = 'd';

// 	int res_toupper;
// 	res_toupper = ft_toupper(input_ft_toupper);
// 	printf("\nTest for ft_toupper: \n\tft_toupper(\'d\') = %d\n", res_toupper);
// 	printf("\t\tThe char for #%d is: %c", res_toupper, res_toupper);
// 	printf("\n\ttoupper(\'d\') = %d\n", toupper(input_ft_toupper));
// 	printf("\t\tThe char for #%d is: %c\n", toupper('d'), toupper('d'));

// 	// Test for ft_tolower
// 	int input_ft_tolower;
// 	input_ft_tolower = 'Z';

// 	int res_ft_tolower;
// 	res_ft_tolower = ft_tolower(input_ft_tolower);
// 	printf("\nTest for ft_tolower: \n\tft_tolower(\'Z\') = %d\n", res_ft_tolower);
// 	printf("\t\tThe char for #%d is: %c", res_ft_tolower, res_ft_tolower);
// 	printf("\n\ttolower(\'Z\') = %d\n", tolower(input_ft_tolower));
// 	printf("\t\tThe char for #%d is: %c\n", tolower('Z'), tolower('Z'));

// 	// Test for ft_isalpha
// 	int input_ft_isalpha;
// 	input_ft_isalpha = 'Z';

// 	int res_ft_isalpha;
// 	res_ft_isalpha = ft_isalpha(input_ft_isalpha);
// 	printf("\nTest for ft_isalpha: \n\tft_isalpha(\'Z\') = %d\n", res_ft_isalpha);
// 	printf("\tisalpha(\'Z\') = %d\n", isalpha(input_ft_isalpha));

// 	int input_ft_isalpha_2;
// 	input_ft_isalpha_2 = 'p';

// 	int res_ft_isalpha_2;
// 	res_ft_isalpha_2 = ft_isalpha(input_ft_isalpha_2);
// 	printf("\n\tft_isalpha(\'p\') = %d\n", res_ft_isalpha_2);
// 	printf("\tisalpha(\'p\') = %d\n", isalpha(input_ft_isalpha_2));

// 	int input_ft_isalpha_3;
// 	input_ft_isalpha_3 = '9';

// 	int res_ft_isalpha_3;
// 	res_ft_isalpha_3 = ft_isalpha(input_ft_isalpha_3);
// 	printf("\n\tft_isalpha(\'9\') = %d\n", res_ft_isalpha_3);
// 	printf("\tisalpha(\'9\') = %d\n", isalpha(input_ft_isalpha_3));

// 	// Test for ft_isdigit
// 	int input_ft_isdigit;
// 	input_ft_isdigit = '4';

// 	int res_ft_isdigit;
// 	res_ft_isdigit = ft_isdigit(input_ft_isdigit);
// 	printf("\nTest for ft_isdigit: \n\tft_isdigit(\'4\') = %d\n", res_ft_isdigit);
// 	printf("\tisdigit(\'4\') = %d\n", isdigit(input_ft_isdigit));

// 	int input_ft_isdigit_2;
// 	input_ft_isdigit_2 = '9';

// 	int res_ft_isdigit_2;
// 	res_ft_isdigit_2 = ft_isdigit(input_ft_isdigit_2);
// 	printf("\n\tft_isdigit(\'9\') = %d\n", res_ft_isdigit_2);
// 	printf("\tisdigit(\'9\') = %d\n", isdigit(input_ft_isdigit_2));

// 	int input_ft_isdigit_3;
// 	input_ft_isdigit_3 = 'a';

// 	int res_ft_isdigit_3;
// 	res_ft_isdigit_3 = ft_isdigit(input_ft_isdigit_3);
// 	printf("\n\tft_isdigit(\'a\') = %d\n", res_ft_isdigit_3);
// 	printf("\tisdigit(\'a\') = %d\n", isdigit(input_ft_isdigit_3));

// 	// Test for ft_isalnum
// 	int input_ft_isalnum;
// 	input_ft_isalnum = 'Z';

// 	int res_ft_isalnum;
// 	res_ft_isalnum = ft_isalnum(input_ft_isalnum);
// 	printf("\nTest for ft_isalnum: \n\tft_isalnum(\'Z\') = %d\n", res_ft_isalnum);
// 	printf("\tisalnum(\'Z\') = %d\n", isalnum(input_ft_isalnum));

// 	int input_ft_isalnum_2;
// 	input_ft_isalnum_2 = '5';

// 	int res_ft_isalnum_2;
// 	res_ft_isalnum_2 = ft_isalnum(input_ft_isalnum_2);
// 	printf("\n\tft_isalnum(\'5\') = %d\n", res_ft_isalnum_2);
// 	printf("\tisalnum(\'5\') = %d\n", isalnum(input_ft_isalnum_2));

// 	int input_ft_isalnum_3;
// 	input_ft_isalnum_3 = '\'';

// 	int res_ft_isalnum_3;
// 	res_ft_isalnum_3 = ft_isalnum(input_ft_isalnum_3);
// 	printf("\n\tft_isalnum(\'\'\') = %d\n", res_ft_isalnum_3);
// 	printf("\tisalnum(\'\'\') = %d\n", isalnum(input_ft_isalnum_3));

// 	// Test for ft_isascii
// 	int input_ft_isascii;
// 	input_ft_isascii = 'Z';

// 	int res_ft_isascii;
// 	res_ft_isascii = ft_isascii(input_ft_isascii);
// 	printf("\nTest for ft_isascii: \n\tft_isascii(\'Z\') = %d\n", res_ft_isascii);
// 	printf("\tisascii(\'Z\') = %d\n", isascii(input_ft_isascii));

// 		// Need a false test here instead
// 	int input_ft_isascii_2;
// 	input_ft_isascii_2 = ' ';

// 	int res_ft_isascii_2;
// 	res_ft_isascii_2 = ft_isascii(input_ft_isascii_2);
// 	printf("\n\tft_isascii(\' \') = %d\n", res_ft_isascii_2);
// 	printf("\tisascii(\' \') = %d\n", isascii(input_ft_isascii_2));

// 	// Test for ft_isprint
// 	int input_ft_isprint;
// 	input_ft_isprint = 'Z';

// 	int res_ft_isprint;
// 	res_ft_isprint = ft_isascii(input_ft_isprint);
// 	printf("\nTest for ft_isprint: \n\tft_isprint(\'Z\') = %d\n", res_ft_isprint);
// 	printf("\tisprint(\'Z\') = %d\n", isprint(input_ft_isprint));

// 	int input_ft_isprint_2;
// 	input_ft_isprint_2 = ' ';

// 	int res_ft_isprint_2;
// 	res_ft_isprint_2 = ft_isascii(input_ft_isprint_2);
// 	printf("\n\tft_isprint(\' \') = %d\n", res_ft_isprint_2);
// 	printf("\tisprint(\' \') = %d\n", isprint(input_ft_isprint_2));



// 	// Test for ft_strndup
// 	// char *input_ft_strndup;
// 	// input_ft_strndup = "I am a string..";

// 	// char *res_ft_strndup;
// 	// res_ft_strndup = ft_strndup(input_ft_strndup, 16);
// 	// printf("\nTest for ft_strndup: \n\tft_strndup(\'I am a string..\', 16) = %s\n", res_ft_strndup);
// 	// printf("\tstrndup(\'I am a string..\', 16) = %s\n", strndup(input_ft_strndup, 16));

// 	// char *res_ft_strndup_2;
// 	// res_ft_strndup_2 = ft_strndup(input_ft_strndup, 6);
// 	// printf("\n\tft_strndup(\'I am a string..\', 6) = %s\n", res_ft_strndup_2);
// 	// printf("\tstrndup(\'I am a string..\', 6) = %s\n", strndup(input_ft_strndup, 6));

// 	// Test for ft_memset
// 	printf("\nTest for ft_memset: \n");
//     char str_ft_memset[50] = "GeeksForGeeks is for programming geeks.";
//     printf("\tBefore ft_memset(): %s\n", str_ft_memset);

//     // Fill 8 characters starting from str[13] with '.'
//     ft_memset(str_ft_memset + 13, '.', 8 * sizeof(char));
//     printf("\tAfter ft_memset():  %s\n", str_ft_memset);

//     // memset() comparison here
//     char str_memset[50] = "GeeksForGeeks is for programming geeks.";
//     printf("\n\tBefore memset(): %s\n", str_memset);

//     // Fill 8 characters starting from str[13] with '.'
//     memset(str_memset + 13, '.', 8 * sizeof(char));

//     printf("\tAfter ft_memset():  %s\n", str_memset);

//     // Test for ft_bzero
// 	printf("\nTest for ft_bzero: \n");
// 	char str_ft_bzero[15] = "Hello there!";

// 	printf("\tBefore ft_bzero: %s\n", str_ft_bzero);
// 	ft_bzero(str_ft_bzero, 5);
//     printf("\tAfter ft_bzero: %s\n", str_ft_bzero);

//     char str_ft_bzero_2[1] = "1";

// 	printf("\tBefore ft_bzero: %s\n", str_ft_bzero_2);
// 	ft_bzero(str_ft_bzero_2, 1);
//     printf("\tAfter ft_bzero: %s\n", str_ft_bzero_2);

//     // Test for ft_memcpy
// 	printf("\nTest for ft_memcpy: \n");
// 	char str_memcpy_src[15] = "Hello there!";
// 	char str_memcpy_dst[15] = "xxxxxxxxxxxx";

// 	printf("\tDestination string before memcpy: %s\n", str_memcpy_dst);
// 	memcpy(str_memcpy_dst, str_memcpy_src, 12);

//     printf("\tAfter memcpy: %s\n", str_memcpy_dst);

//     char str_ft_memcpy_src[15] = "Hello there!";
// 	char str_ft_memcpy_dst[15] = "xxxxxxxxxxxx";

//     printf("\tDestination string before ft_memcpy: %s\n", str_ft_memcpy_dst);
// 	ft_memcpy(str_ft_memcpy_dst, str_ft_memcpy_src, 12);

//     printf("\tAfter ft_memcpy: %s\n", str_ft_memcpy_dst);

//     // Test for ft_memmove
// 	printf("\nTest for ft_memmove: \n");
// 	char str_memmove_src[15] = "Hello there!";
// 	char str_memmove_dst[15] = "xxxxxxxxxxxx";

// 	printf("\tDestination string before memmove: %s\n", str_memmove_dst);
// 	memmove(str_memmove_dst, str_memmove_src, 3);

//     printf("\tAfter memmove: %s\n", str_memmove_dst);





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
