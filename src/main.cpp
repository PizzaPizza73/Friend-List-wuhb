#include <coreinit/debug.h>
#include <whb/proc.h>
#include <sysapp/title.h>
#include <sysapp/launch.h>

int main() {
	WHBProcInit();

	if (WHBProcIsRunning()) {
		if (
			SYSCheckTitleExists(0x000500301001500A) || // * JPN
			SYSCheckTitleExists(0x000500301001510A) || // * USA
			SYSCheckTitleExists(0x000500301001520A)    // * EUR
		) {
			_SYSSwitchTo(SYSAPP_PFID_FRIENDLIST);
		} else {
			OSFatal("Failed to find Friend List");
		}

		while(WHBProcIsRunning()) {}
	}

	return 0;
}
