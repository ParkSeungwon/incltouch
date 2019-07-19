#include<chrono>
#include<experimental/filesystem>
#include<thread>
#include<fmt/format.h>
using namespace std;
using namespace experimental::filesystem;

int main()
{
	const path p{"/var/games/angband/save/Zeta"};
	fmt::print("starting {}\n", p.string());
	for(int i=0; ;) {
		auto t = chrono::system_clock::now();
		this_thread::sleep_for(5s);
		if(last_write_time(p) > t) {
			string s = "/tmp/Zeta" + fmt::format("{:02d}", i++);
			remove(s);
			copy(p, s);
			fmt::print("wrote {}", s + '\n');
		}
	}
}
