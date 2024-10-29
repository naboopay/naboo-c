#ifndef validation_error_loc_inner_TEST
#define validation_error_loc_inner_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define validation_error_loc_inner_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/validation_error_loc_inner.h"
validation_error_loc_inner_t* instantiate_validation_error_loc_inner(int include_optional);



validation_error_loc_inner_t* instantiate_validation_error_loc_inner(int include_optional) {
  validation_error_loc_inner_t* validation_error_loc_inner = NULL;
  if (include_optional) {
    validation_error_loc_inner = validation_error_loc_inner_create(
    );
  } else {
    validation_error_loc_inner = validation_error_loc_inner_create(
    );
  }

  return validation_error_loc_inner;
}


#ifdef validation_error_loc_inner_MAIN

void test_validation_error_loc_inner(int include_optional) {
    validation_error_loc_inner_t* validation_error_loc_inner_1 = instantiate_validation_error_loc_inner(include_optional);

	cJSON* jsonvalidation_error_loc_inner_1 = validation_error_loc_inner_convertToJSON(validation_error_loc_inner_1);
	printf("validation_error_loc_inner :\n%s\n", cJSON_Print(jsonvalidation_error_loc_inner_1));
	validation_error_loc_inner_t* validation_error_loc_inner_2 = validation_error_loc_inner_parseFromJSON(jsonvalidation_error_loc_inner_1);
	cJSON* jsonvalidation_error_loc_inner_2 = validation_error_loc_inner_convertToJSON(validation_error_loc_inner_2);
	printf("repeating validation_error_loc_inner:\n%s\n", cJSON_Print(jsonvalidation_error_loc_inner_2));
}

int main() {
  test_validation_error_loc_inner(1);
  test_validation_error_loc_inner(0);

  printf("Hello world \n");
  return 0;
}

#endif // validation_error_loc_inner_MAIN
#endif // validation_error_loc_inner_TEST
