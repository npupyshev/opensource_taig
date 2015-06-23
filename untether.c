#include <mach/mach.h>
#include <mach/message.h>
#include <IOKit/IOKitLib.h>
#include <CoreFoundation/CoreFoundation.h>

unsigned char datablob[116];
char obfuscation_key[16] = "rgca/[204';b/[]/";

/* sub_D91C */
void *read_file_contents(const char *path, size_t *length)
{
  void *contents;

  contents = NULL;
  int fd = open(path, 0);
  if ( fd >= 0 ) {
    lseek(fd, 0, SEEK_END);
    size_t file_length = lseek(fd, 0, SEEK_CUR);
    lseek(fd, 0, SEEK_SET);
    void *file_buffer = malloc(length);
    if (file_buffer) {
    	int ret;
    	while ((ret = read(fd, fileBuffer, length)) == -1) {
	  		if (*__error() != 35 && *__error() != 4) {
        		free(fileBuffer);
      		}
    	}
    	if (ret == 0) {
    		*length = file_length;
    		contents = file_buffer;
    	}
    }
    if ( fd >= 0 ) close(fd);
  }
  return ret;
}

/* sub_c770 */
mach_msg_return_t receive_mach_msg(mach_port_t rcv_name, mach_msg_header_t *msg, mach_msg_size_t rcv_size)
{
	return mach_msg(msg, MACH_RCV_MSG, 0, rcv_size, rcv_name, 0, 0);
}

/* sub_e568 */
void setup_watchdog_timer(int value)
{
	io_service_t timerservice = IOServiceGetMatchingService(kIOMasterPortDefault, IOServiceMatching("IOWatchDogTimer"));
	if (timerservice != 0) {
		CFNumberRef cfval = CFNumberCreate(kCFAllocatorDefault, kCFNumberIntType, &value);
		IORegistryEntrySetCFProperties(timerservice, cfval);
		IOObjectRelease(timerservice);
		CFRelease(cfval);
	}
}

/* InitFunc_0 */

__attribute__((constructor))
void InitFunc()
{
	datablob[0] = 0xD8;
	datablob[1] = 0xC5;
	datablob[2] = 0xD0;
	datablob[3] = 0xC9;
	datablob[4] = 0xFA;
	datablob[5] = 0xD1;
	datablob[6] = 0xFA;
	datablob[7] = 0xE1;
	datablob[8] = 0xD;
	datablob[9] = 0xE5;
	datablob[10] = 0xF3;
	datablob[11] = 0xA0;
	datablob[12] = 0xE3;
	datablob[13] = 0xD2;
	datablob[14] = 0xFA;
	datablob[15] = 0xD8;
	datablob[16] = 0xC5;
	datablob[17] = 0xC8;
	datablob[18] = 0xC5;
	datablob[19] = 8;
	datablob[20] = 0xA6;
	datablob[21] = 0xF4;
	datablob[22] = 0xE0;
	datablob[23] = 0xF8;
	datablob[24] = 0xEF;
	datablob[25] = 0xE6;
	datablob[26] = 0x9E;
	datablob[27] = 0xE7;
	datablob[28] = 0xF8;
	datablob[29] = 0xD8;
	datablob[30] = 0xC5;
	datablob[31] = 0xC8;
	datablob[32] = 0xC5;
	datablob[33] = 8;
	datablob[34] = 0xBB;
	datablob[35] = 0xE1;
	datablob[36] = 0xF2;
	datablob[37] = 0xF7;
	datablob[38] = 0xF0;
	datablob[39] = 5;
	datablob[40] = 0xA4;
	datablob[41] = 0xFA;
	datablob[42] = 0xCA;
	datablob[43] = 0xD1;
	datablob[44] = 0xE9;
	datablob[45] = 0xB4;
	datablob[46] = 4;
	datablob[47] = 0xD8;
	datablob[48] = 0xC5;
	datablob[49] = 0xC8;
	datablob[50] = 0xC5;
	datablob[51] = 8;
	datablob[52] = 0xB4;
	datablob[53] = 0xF8;
	datablob[54] = 0xEF;
	datablob[55] = 0xFE;
	datablob[56] = 0xF1;
	datablob[57] = 0xFB;
	datablob[58] = 0xAD;
	datablob[59] = 9;
	datablob[60] = 0xD4;
	datablob[61] = 0xD1;
	datablob[62] = 0xE7;
	datablob[63] = 0xB9;
	datablob[64] = 0xB0;
	datablob[65] = 0;
	datablob[66] = 0xD8;
	datablob[67] = 0xC5;
	datablob[68] = 0xD3;
	datablob[69] = 0xAF;
	datablob[70] = 0xE7;
	datablob[71] = 0xC6;
	datablob[72] = 14;
	datablob[73] = 0xF9;
	datablob[74] = 0xFA;
	datablob[75] = 0xDF;
	datablob[76] = 0xF2;
	datablob[77] = 0xB3;
	datablob[78] = 9;
	datablob[79] = 0xD4;
	datablob[80] = 0xD9;
	datablob[81] = 0xF9;
	datablob[82] = 0x9E;
	datablob[83] = 4;
	datablob[84] = 0xBD;
	datablob[85] = 0x9F;
	datablob[86] = 0xB0;
	datablob[87] = 0xAB;
	datablob[88] = 0xFA;
	datablob[89] = 0xCC;
	datablob[90] = 0x13;
	datablob[91] = 0xF2;
	datablob[92] = 0xE4;
	datablob[93] = 0xE1;
	datablob[94] = 0xE6;
	datablob[95] = 0xA8;
	datablob[96] = 0xFC;
	datablob[97] = 0xCC;
	datablob[98] = 0xCF;
	datablob[99] = 0xFA;
	datablob[100] = 0xF;
	datablob[101] = 0xBD;
	datablob[102] = 0x9F;
	datablob[103] = 0xB0;
	datablob[104] = 0xAB;
	datablob[105] = 0xFA;
	datablob[106] = 0xCC;
	datablob[107] = 0x18;
	datablob[108] = 0xFB;
	datablob[109] = 0xDD;
	datablob[110] = 0xDF;
	datablob[111] = 0xE6;
	datablob[112] = 0xB1;
	datablob[113] = 0xEB;
	datablob[114] = 0xD4;
	datablob[115] = 0xFA;
}

/* sub_11808 */
void deobfuscate_strings()
{
	char buffer[100];
	memset(buffer, 0, 100);
	int i;

	memset(buffer, 0, 100);
	for (i=0; i<=15; i++) buffer[i] = (datablob[i] + 99)^obfuscation_key[i&15];
	printf("string1: %s\n", buffer);

	memset(buffer, 0, 100);
	for (i=0; i<=14; i++) buffer[i] = (datablob[i+0xf] + 99)^obfuscation_key[i&15];
	printf("string2: %s\n", buffer);

	memset(buffer, 0, 100);
	for (i=0; i<=19; i++) buffer[i] = (datablob[i+0x2f] + 99)^obfuscation_key[i&15];
	printf("string3: %s\n", buffer);

	memset(buffer, 0, 100);
	for (i=0; i<=18; i++) buffer[i] = (datablob[i+0x1d] + 99)^obfuscation_key[i&15];
	printf("string4: %s\n", buffer);

	memset(buffer, 0, 100);
	for (i=0; i<=18; i++) buffer[i] = (datablob[i+0x42] + 99)^obfuscation_key[i&15];
	printf("string5: %s\n", buffer);

	memset(buffer, 0, 100);
	for (i=0; i<=17; i++) buffer[i] = (datablob[i+0x54] + 99)^obfuscation_key[i&15];
	printf("string6: %s\n", buffer);

	memset(buffer, 0, 100);
	for (i=0; i<=15; i++) buffer[i] = (datablob[i+0x65] + 99)^obfuscation_key[i&15];
	printf("string7: %s\n", buffer);
}

/* start */
int main(int argc, char **argv, char **envp)
{
	/* not yet implemented */
	
	
	/* DEBUG */
	deobfuscate_strings();
}
