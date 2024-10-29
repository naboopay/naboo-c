#ifndef wallet_TEST
#define wallet_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define wallet_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/wallet.h"
wallet_t* instantiate_wallet(int include_optional);



wallet_t* instantiate_wallet(int include_optional) {
  wallet_t* wallet = NULL;
  if (include_optional) {
    wallet = wallet_create(
    );
  } else {
    wallet = wallet_create(
    );
  }

  return wallet;
}


#ifdef wallet_MAIN

void test_wallet(int include_optional) {
    wallet_t* wallet_1 = instantiate_wallet(include_optional);

	cJSON* jsonwallet_1 = wallet_convertToJSON(wallet_1);
	printf("wallet :\n%s\n", cJSON_Print(jsonwallet_1));
	wallet_t* wallet_2 = wallet_parseFromJSON(jsonwallet_1);
	cJSON* jsonwallet_2 = wallet_convertToJSON(wallet_2);
	printf("repeating wallet:\n%s\n", cJSON_Print(jsonwallet_2));
}

int main() {
  test_wallet(1);
  test_wallet(0);

  printf("Hello world \n");
  return 0;
}

#endif // wallet_MAIN
#endif // wallet_TEST
