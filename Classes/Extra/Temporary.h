#define SCENE_FUNC(__TYPE__) \
	static cocos2d::Scene* scene( void ) \
{ \
	cocos2d::Scene* pScene = cocos2d::Scene::create(); \
	__TYPE__ *pRet = new __TYPE__(); \
	if( pRet && pRet->init() ) \
{ \
	pRet->autorelease(); \
	pScene->addChild( pRet ); \
	return pScene; \
} \
else \
{ \
	delete pRet; \
	pRet = NULL; \
	return NULL; \
} \
}




// Singleton Template
template <class T> class Singleton {
private:
	static T* theInstance;

public:
	~Singleton(){
	}
	Singleton(){
	}

	static T* GetInstance() {
		if ( theInstance == NULL ) {
			theInstance = new T();
		}
		return theInstance;
	}
	template <class C> static T* GetInstance( C val ) {
		if ( theInstance == NULL ) {
			theInstance = new T(val);
		}
		return theInstance;
	}
	template <class C, class M> static T* GetInstance( C val1, M val2 ) {
		if ( theInstance == NULL ) {
			theInstance = new T(val1, val2);
		}
		return theInstance;
	}
	static void Release()
	{
		delete _Singleton;
		_Singleton = NULL;
	}
};

template <class T>  T* Singleton<T>::theInstance = NULL;