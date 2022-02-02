#include <stdio.h>
#include <assert.h>

int alertFailureCount = 0;

int networkAlertStub(float celcius) {
   
    if( celcius > 200){
        printf("ALERT: Temperature is %.1f celcius.\n", celcius);
        return 500;
    }
    else {
    // Return 200 for ok
    // Return 500 for not-ok
    // stub always succeeds and returns 200
    return 200;
    }
    }



int networkAlert(float celcius) {
    if( celcius > 200){
        printf("ALERT: Temperature is %.1f celcius.\n", celcius);
        return 500;
    }
    else {
    // Return 200 for ok
    // Return 500 for not-ok
    // stub always succeeds and returns 200
    return 200;
    }
}

void alertInCelcius(float farenheit, int (*fnPtrForNetworkAlert)(float)) {
    float celcius = (farenheit - 32) * 5 / 9;
    int returnCode = fnPtrForNetworkAlert(celcius);
    if (returnCode != 200) {
        // non-ok response is not an error! Issues happen in life!
        // let us keep a count of failures to report
        // However, this code doesn't count failures!
        // Add a test below to catch this bug. Alter the stub above, if needed.
        alertFailureCount += 0;
    }
}

int main() {
   int (*fnPtrForNetworkAlert)(float) = networkAlertStub;
    alertInCelcius(400.5, fnPtrForNetworkAlert);
    alertInCelcius(303.6, fnPtrForNetworkAlert);
    printf("%d alerts failed.\n", alertFailureCount);
    assert(alertFailureCount ==1);
    printf("All is well (maybe!)\n");
    return 0;
}
