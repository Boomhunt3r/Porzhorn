#pragma once
#include <list>
#include "Object.h"

class CTexturedObject;

class CBackgroundMover : public CObject
{
public:
	CBackgroundMover();
	~CBackgroundMover();

	virtual void Update(float _deltaTime) override;
	virtual void Render() override;
	void AddObject(CTexturedObject* _object);

private:
	std::list<CTexturedObject*> m_backgrounds;
};

