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
    
	// 메뉴 아이템 생성 및 초기화

	MenuItemFont::setFontSize(24);
	MenuItemFont::setFontName("Couruer New");

	auto menuItem1 = MenuItemFont::create(
		"Get",
		CC_CALLBACK_1(HelloWorld::onGetTest, this));
	menuItem1->setColor(Color3B::BLACK);

	auto menuItem2 = MenuItemFont::create(
		"Post",
		CC_CALLBACK_1(HelloWorld::onPostTest, this));
	menuItem2->setColor(Color3B::BLACK);

	auto menuItem3 = MenuItemFont::create(
		"Post Binary",
		CC_CALLBACK_1(HelloWorld::onPostBinaryTest, this));
	menuItem3->setColor(Color3B::BLACK);

	// 메뉴 생성
	auto menu = Menu::create(menuItem1, menuItem2, menuItem3, nullptr);

	// 메뉴 배치
	menu->alignItemsVertically();

	// Layer에 메뉴 객체 추가
	this->addChild(menu);

	// Response Code Label
	_labelSttusCode = LabelTTF::create("HTTP Status Code", "Courier New", 20);
	_labelSttusCode->setPosition(Vec2(240, 260));
	_labelSttusCode->setColor(Color3B::BLUE);
	this->addChild(_labelSttusCode);
    
    return true;
}

void HelloWorld::onGetTest(Ref* sender)
{

	// Test1
	{
		HttpRequest* request = new HttpRequest();
		request->setUrl("http://just-make-this-request-failed.com");
		request->setRequestType(HttpRequest::Type::GET);
		request->setResponseCallback(this, httpresponse_selector(HelloWorld::onHttpRequestCompeted));
		request->setTag("GET test1");
		request->release();
	}

	// Test2
	{
		HttpRequest* request = new HttpRequest();
		// required fileds
		request->setUrl("http://httpbin.org/ip");
		request->setRequestType(HttpRequest::Type::GET);
		request->setResponseCallback(this, httpresponse_selector(HelloWorld::onHttpRequestCompeted));
		// optional field
		request->setTag("GET test2");
		HttpClient::getInstance()->send(request);

		// don't forget to release it, pair to now
		request->release();
	}

	// Test3
	{
		HttpRequest* request = new HttpRequest();
		// required fileds
		request->setUrl("http://httpbin.org/get");
		request->setRequestType(HttpRequest::Type::GET);
		request->setResponseCallback(this, httpresponse_selector(HelloWorld::onHttpRequestCompeted));
		// optional field
		request->setTag("GET test3");
		HttpClient::getInstance()->send(request);
		request->release();
	}

	_labelSttusCode->setString("waiting...");
}

void HelloWorld::onPostTest(Ref* sender)
{
	// Test1
	{
		HttpRequest* request = new HttpRequest();
		request->setUrl("http://httpbin.org/post");
		request->setRequestType(HttpRequest::Type::POST);
		request->setResponseCallback(this, httpresponse_selector(HelloWorld::onHttpRequestCompeted));

		// write the post data
		const char* postData = "visitor-cocos2d&TestSuite=Extensions Test/NetWorkTest";
		request->setRequestData(postData, strlen(postData));
		request->setTag("Post test1");
		HttpClient::getInstance()->send(request);
		request->release();
	}

	// Test2 : set Content Type
	{
		HttpRequest* request = new HttpRequest();
		request->setUrl("http://httpbin.org/post");
		request->setRequestType(HttpRequest::Type::POST);
		std::vector<std::string> headers;
		headers.push_back("Content-Type : application/json; charset=utf-8");
		request->setHeaders(headers);
		request->setResponseCallback(this, httpresponse_selector(HelloWorld::onHttpRequestCompeted));

		// write the post data
		const char* postData = "visitor-cocos2d&TestSuite=Extensions Test/NetWorkTest";
		request->setRequestData(postData, strlen(postData));
		request->setTag("Post test2");
		HttpClient::getInstance()->send(request);
		request->release();
	}

	// Test3
	{
		HttpRequest* request = new HttpRequest();
		// required fileds
		request->setUrl("http://httpbin.org/get");
		request->setRequestType(HttpRequest::Type::GET);
		request->setResponseCallback(this, httpresponse_selector(HelloWorld::onHttpRequestCompeted));
		// optional field
		request->setTag("GET test3");
		HttpClient::getInstance()->send(request);
		request->release();
	}

	_labelSttusCode->setString("waiting...");
}

void HelloWorld::onPostBinaryTest(Ref* sender)
{
	// Test1
	{
		HttpRequest* request = new HttpRequest();
		request->setUrl("http://httpbin.org/post");
		request->setRequestType(HttpRequest::Type::POST);
		request->setResponseCallback(this, httpresponse_selector(HelloWorld::onHttpRequestCompeted));

		// write the post data
		//including \0, the strings after \0 should not be cut in response
		char postData[22] = "binary=hello\0\0cocos2d";
		request->setRequestData(postData, 22);
		request->setTag("Post Binary test1");
		HttpClient::getInstance()->send(request);
		request->release();
	}

	_labelSttusCode->setString("waiting...");
}

void HelloWorld::onHttpRequestCompeted(HttpClient *sender, HttpResponse *response)
{
	if (!response)
		return;
	
	// You can get original request type from: response->request->reqType
	if (0 != strlen(response->getHttpRequest()->getTag()))
		log("%s Completed,", response->getHttpRequest()->getTag());
	
	int statusCode = response->getResponseCode();
	char statusString[64] = {};
	sprintf(statusString, "HTTP Status Code : %d,\n tag = %s",
		statusCode, response->getHttpRequest()->getTag());

	_labelSttusCode->setString(statusString);
	log("response code : %d", statusCode);

	if (!response->isSucceed())
	{
		log("response failed");
		log("error buffer : %s", response->getErrorBuffer());
	}

	// dump data
	std::vector<char> *buffer = response->getResponseData();
	printf("Http Test, dump data: ");
	for (unsigned int i = 0; i < buffer->size(); ++i)
		printf("%c", (*buffer)[i]);
		printf("\n");
}

