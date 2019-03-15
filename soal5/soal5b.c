#include <unistd.h>

int main()
{
	execlp("pkill", "pkill", "-f", "soal5",NULL);
}
