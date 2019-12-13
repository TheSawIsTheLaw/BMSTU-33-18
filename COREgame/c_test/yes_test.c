#include "../c_src_headers/yes_link.h"
#include <string.h>
int main()
{
	char* teststr;
	strcpy(teststr, "clown");
	yes(teststr);
}
