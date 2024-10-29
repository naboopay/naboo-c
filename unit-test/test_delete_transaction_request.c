#ifndef delete_transaction_request_TEST
#define delete_transaction_request_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define delete_transaction_request_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/delete_transaction_request.h"
delete_transaction_request_t* instantiate_delete_transaction_request(int include_optional);



delete_transaction_request_t* instantiate_delete_transaction_request(int include_optional) {
  delete_transaction_request_t* delete_transaction_request = NULL;
  if (include_optional) {
    delete_transaction_request = delete_transaction_request_create(
      "0"
    );
  } else {
    delete_transaction_request = delete_transaction_request_create(
      "0"
    );
  }

  return delete_transaction_request;
}


#ifdef delete_transaction_request_MAIN

void test_delete_transaction_request(int include_optional) {
    delete_transaction_request_t* delete_transaction_request_1 = instantiate_delete_transaction_request(include_optional);

	cJSON* jsondelete_transaction_request_1 = delete_transaction_request_convertToJSON(delete_transaction_request_1);
	printf("delete_transaction_request :\n%s\n", cJSON_Print(jsondelete_transaction_request_1));
	delete_transaction_request_t* delete_transaction_request_2 = delete_transaction_request_parseFromJSON(jsondelete_transaction_request_1);
	cJSON* jsondelete_transaction_request_2 = delete_transaction_request_convertToJSON(delete_transaction_request_2);
	printf("repeating delete_transaction_request:\n%s\n", cJSON_Print(jsondelete_transaction_request_2));
}

int main() {
  test_delete_transaction_request(1);
  test_delete_transaction_request(0);

  printf("Hello world \n");
  return 0;
}

#endif // delete_transaction_request_MAIN
#endif // delete_transaction_request_TEST
