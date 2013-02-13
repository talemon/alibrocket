// The following ifdef block is the standard way of creating macros which make exporting 
// from a DLL simpler. All files within this DLL are compiled with the ALIBROCKET_EXPORTS
// symbol defined on the command line. this symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see 
// ALIBROCKET_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#ifdef ALIBROCKET_EXPORTS
#define ALIBROCKET_API __declspec(dllexport)
#else
#define ALIBROCKET_API __declspec(dllimport)
#endif

static double time_frequency;
static LARGE_INTEGER time_startup;
static Rocket::Core::Context* context = NULL;
ENGINE_VARS* eng_vars;

class MySystemInterface : public Rocket::Core::SystemInterface
{
public:
	/// Get the number of seconds elapsed since the start of the application
	/// @returns Seconds elapsed
	virtual float GetElapsedTime();
	void Initialize();
};

extern "C"
{
	ALIBROCKET_API void RockInit(void);
	ALIBROCKET_API void RockDestroy(void);
	ALIBROCKET_API void RockUpdate(void);
}