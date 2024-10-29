#ifndef http_validation_error_TEST
#define http_validation_error_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define http_validation_error_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/http_validation_error.h"
http_validation_error_t* instantiate_http_validation_error(int include_optional);



http_validation_error_t* instantiate_http_validation_error(int include_optional) {
  http_validation_error_t* http_validation_error = NULL;
  if (include_optional) {
    http_validation_error = http_validation_error_create(
      list_createList()
    );
  } else {
    http_validation_error = http_validation_error_create(
      list_createList()
    );
  }

  return http_validation_error;
}


#ifdef http_validation_error_MAIN

void test_http_validation_error(int include_optional) {
    http_validation_error_t* http_validation_error_1 = instantiate_http_validation_error(include_optional);

	cJSON* jsonhttp_validation_error_1 = http_validation_error_convertToJSON(http_validation_error_1);
	printf("http_validation_error :\n%s\n", cJSON_Print(jsonhttp_validation_error_1));
	http_validation_error_t* http_validation_error_2 = http_validation_error_parseFromJSON(jsonhttp_validation_error_1);
	cJSON* jsonhttp_validation_error_2 = http_validation_error_convertToJSON(http_validation_error_2);
	printf("repeating http_validation_error:\n%s\n", cJSON_Print(jsonhttp_validation_error_2));
}

int main() {
  test_http_validation_error(1);
  test_http_validation_error(0);

  printf("Hello world \n");
  return 0;
}

#endif // http_validation_error_MAIN
#endif // http_validation_error_TEST
