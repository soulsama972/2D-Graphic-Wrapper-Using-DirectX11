#pragma once
#include <chrono>
#include<iostream>
#include<ctime>
#include <chrono>
#include<Windows.h>
#include<string>
#include <cstdarg>
#define SafeDelete(x) if (x != nullptr) {x->Release(); x = nullptr;}
#define SafeDeletePtr(x) if(x){delete x; x = nullptr;}
#define SafeDeletePtrArr(x) if(x){delete[] x; x = nullptr;}
#define CheckFAILED(x) if(FAILED(x)) { MessageBoxA(NULL,std::to_string(__LINE__).c_str(),__FILE__,MB_OK); exit(0);}
#define CheckAlloc(x) if(x == 0) {MessageBoxA(NULL,std::to_string(__LINE__).c_str(),__FILE__,MB_OK); exit(0);}

template<typename T>
inline void * ForceCast(T t)
{
	union MyUnion
	{
		T t;
		void* v;
	};
	MyUnion u;
	u.t = t;
	return u.v;
}


inline std::string GetPath()
{
	char buffer[256];
	GetModuleFileNameA(NULL, buffer, 256);
	std::string path(buffer);
	path = path.substr(0, path.find_last_of('\\'));
	path = path.substr(0, path.find_last_of('\\'));
	path = path.substr(0, path.find_last_of('\\') + 1);
	return path;
}

