#include "HelloWorldScene.h"

// rapidjson기능을 사용하기 위해 JSON용 객체 변수용 header를 include한다. 
#include "rapidjson/document.h"

// rapidjson기능을 사용하기 위해 JSON용 reader header를 include한다. 
#include "rapidjson/reader.h"

USING_NS_CC;

// rapidjson의 namespace를 선언한다.
using namespace rapidjson;

Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !LayerColor::initWithColor(Color4B(255,255,255,255)) )
    {
        return false;
    }
    
	// JSON을 관리할 Document 객체의 변수를 선언한다.
	// Default template parameter uses UTF8 and MemoryPoolAllocator
	Document document;
	

	/*파일의 실제 디렉터리를 구한다. 각 플랫폼마다 서로 다른 디렉터리가 나오더라도 걱정할 필요는 없다. 
	  이 함수가 알아서 각 플랫폼별로 실제 디렉터리를 구할 것 이다. */
	std::string fileName = FileUtils::getInstance()->fullPathForFilename("data/test_data.json");
	log("[%s]", fileName.c_str());

	// 파일 데이터를 문자열로 읽어들인다.
	std::string clearData = FileUtils::getInstance()->getStringFromFile(fileName);
    
	if (document.Parse<0>(clearData.c_str()).HasParseError())
	{
		log(document.GetParseError());
		return 1;
	}

	std::string str1 = document["hello"].GetString();
#if(CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
	this->log2("hello = %s\n", str1.c_str());
#else
	log("hello = %s\n", str1.c_str());
#endif
	int n1 = document["i"].GetInt();
	log("i=%d\n", n1);

	bool isT = document["t"].GetBool();
	log("i=%d\n", isT);

	const rapidjson::Value& a = document["a"];
	for (SizeType i = 0; i < a.Size(); ++i)
		log("a=%d", a[i].GetInt());

    return true;
}


#if(CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
void HelloWorld::log2(const char *pszFormat, ...)
{
	static const int kMAxLogLen = 16 * 1024;

	char szBuf[kMAxLogLen];

	va_list ap;
	va_start(ap, pszFormat);
	vsnprintf_s(szBuf, kMAxLogLen, kMAxLogLen, pszFormat, ap);
	va_end(ap);

	WCHAR wszBuf[kMAxLogLen] = { 0 };

	//   MultiByteToWideChar(CP_UTF8, 0, tempBuf, -1, wszBuf, sizeof(wszBuf));
	// Window 환경에선 한글이 깨져나오는데 이는 unicode가 맞지않기때문이다
	// 따라서 이를 ASCII로 바꾸도록 한다.
	MultiByteToWideChar(CP_UTF8, 0, szBuf, -1, wszBuf, sizeof(wszBuf));
	OutputDebugStringW(wszBuf);
	OutputDebugStringA("\n");

	WideCharToMultiByte(CP_ACP, 0, wszBuf, sizeof(wszBuf), szBuf, sizeof(szBuf), nullptr, FALSE);

	printf("%s", szBuf);
}
#endif
