#include <stdlib.h>
#include <stdio.h>
#include <check.h>
#include <string.h>

#include <gtk/gtk.h>
#include "geany.h"

extern TCase *utils_test_case_create(void);
extern TCase *vc_fossil_test_case_create(void);

Suite *
my_suite(void)
{
	Suite *s = suite_create("VC");
	TCase *tc_utils = utils_test_case_create();
	TCase *tc_vc_fossil = vc_fossil_test_case_create();
	suite_add_tcase(s, tc_utils);
	suite_add_tcase(s, tc_vc_fossil);
	return s;
}

int
main(void)
{
	int nf;
	Suite *s = my_suite();
	SRunner *sr = srunner_create(s);
	srunner_run_all(sr, CK_NORMAL);
	nf = srunner_ntests_failed(sr);
	srunner_free(sr);
	return (nf == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
