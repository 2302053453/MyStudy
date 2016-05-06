#include "HelloWorldScene.h"

USING_NS_CC;

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

	xml_document xmlDoc;
	
	std::string fileName = FileUtils::getInstance()->fullPathForFilename("data/test_data.xml");

	xml_parse_result result = xmlDoc.load_file(fileName.c_str());

	if (!result)
	{
		log("Error description: %s", result.description());
		log("Error offset: %d", result.offset);
		return false;
	}

	// Load Symbols
	xml_node nodeResult = xmlDoc.child("result");
	xml_node nodeItems = nodeResult.child("items");
    
	// Type 1
	for (xml_node nodeItem = nodeItems.child("item"); nodeItem; nodeItem = nodeItem.next_sibling("item"))
	{
		std::string symbolName = nodeItem.child("subject").text().get();
#if(CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
		this->log2("%s", symbolName.c_str());
#else
		log("%s", symbolName.c_str());
#endif
	}


	// Type 2
	for (xml_node nodeItem : nodeItems.children("item"))
	{
		std::string symbolName = nodeItem.child("subject").text().get();
#if(CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
		this->log2("%s", symbolName.c_str());
#else
		log("%s", symbolName.c_str());
#endif
	}

	// Type 3
	for (xml_node_iterator iter = nodeItems.begin(); iter != nodeItems.end(); ++iter)
	{
		xpath_node nodeitem = (*iter);
		std::string symbolName = nodeitem.node().child("subject").text().get();
#if(CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
		this->log2("%s", symbolName.c_str());
#else
		log("%s", symbolName.c_str());
#endif
	}

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

	WideCharToMultiByte(CP_ACP, 0, wszBuf,sizeof(wszBuf), szBuf, sizeof(szBuf), nullptr, FALSE);

	printf("%s", szBuf);
}
#endif
