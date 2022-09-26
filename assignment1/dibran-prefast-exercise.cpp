#include "stdafx.h"
#include "stdio.h"
#undef __analysis_assume
#include <CodeAnalysis\SourceAnnotations.h>

#define BUF_SIZE 100
#define STR_SIZE 200

void zeroing();

_Ret_cap_(size) char *my_alloc(size_t size) {
	char *ch  = (char *)malloc(size);
	if(ch != NULL) // FIXED Dereferencing NULL pointer 'ch': Lines: 12, 13
	{
		*ch = NULL;
		ch[size-1] = NULL;  // null terminate here too, to be safe //FIXED Buffer overrun: accessing 'ch', the writable size is 'size' bytes, but '2' bytes might be written
	}
	if (ch != NULL) //FIXED 'return value' might be '0': this does not adhere to the specification for the function 'my_alloc'
	{
		return ch;
	}
	else
	{
		//Out of mem error
		exit(-1);
	}
}

HRESULT input([SA_Post(Tainted=SA_Yes)] _Out_cap_c_(STR_SIZE) char *buf) {
	return (gets_s(buf, STR_SIZE) != NULL)?SEVERITY_SUCCESS:SEVERITY_ERROR; //FIXED 'gets': This function or variable may be unsafe. Consider using gets_s instead.
}

 [returnvalue:SA_Post(Tainted=SA_Yes)] _Ret_cap_c_(STR_SIZE) char *do_read() {
	char *buf = my_alloc(STR_SIZE);
	printf("Allocated a string at %p", buf); //FIXED Non-integer passed as parameter '2' when integer is required in call to 'printf': if a pointer value is being passed, %p should be used
	if (FAILED(input(buf))) { // FIXED Implicit cast between semantically different integer types: testing HRESULT with 'not'. Consider using SUCCEEDED or FAILED macro instead
		printf("error!");
		exit(-1);
	}
	if (*buf == NULL) // FIXED Incorrect operator: assignment of constant in Boolean context. Consider using '==' instead
		printf("empty string");
	return buf;
}

[returnvalue:SA_Post(Tainted=SA_Yes)] void copy_data(_In_count_c_(STR_SIZE) char *buf1,
               _Out_cap_c_(STR_SIZE) char *buf2) {
	memcpy(buf2,buf1,STR_SIZE);
	buf2[STR_SIZE-1] = NULL; // null terminate, just in case
}

int execute([SA_Pre(Tainted=SA_No)] char *buf) {
	return system(buf); // pass buf as command to be executed by the OS
}

void validate([SA_Pre(Tainted=SA_Yes)][SA_Post(Tainted=SA_No)] char *buf) {

    // This is a magical validation method, which turns tainted data
    // into untainted data, for which the code not shown.
    //
    // A real implementation might for example use a whitelist to filter
    // the string.

}

_Check_return_ int test_ready() {
	// code not shown
	return 1;
}

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
	char *buf1 = do_read();
	char *buf2 = my_alloc(STR_SIZE); //FIXED Buffer overrun: accessing 'argument 2', the writable size is '100' bytes, but '200' bytes might be written
	if (buf2 == NULL)
		exit(-1);
	zeroing();
	if (test_ready() == 0) //FIXED Return value ignored: 'test_ready'
	{

	}
	validate(buf1); //FIXED Possible buffer overrun in call to 'execute': use of unchecked value 'buf1'
	execute(buf1);
        
    char* buf3 = do_read();
	copy_data(buf3, buf2); 
	execute(buf2);

    char *buf4 = do_read();
	validate(buf4); //FIXED Possible buffer overrun in call to 'execute': use of unchecked value 'buf4'
    execute(buf4);

}

// *****************************************************************

void zero(_Out_cap_(len) int *buf, int len)
{
    int i;
    for(i = 0; i < len; i++) //FIXED Buffer overrun: accessing 'buf', the writable size is 'len*4' bytes, but '8' bytes might be written
        buf[i] = 0;
}

void zeroboth(_Out_cap_(len) int *buf, int len, 
              _Out_cap_ (len3) int *buf3, int len3)
{
    int *buf2 = buf;
    int len2 = len;
    zero(buf2, len2);
    zero(buf3, len3);
}

void zeroboth2(_Out_cap_(len) int *buf, int len, 
	       _Out_cap_(len3) int *buf3, int len3)
{
	zeroboth(buf, len3, buf3, len);
}

void zeroing()
{
    int elements[200];
    int oelements[100];
    zeroboth2(elements, 200, oelements, 100);
}
