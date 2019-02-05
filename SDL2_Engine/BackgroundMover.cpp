#include "BackgroundMover.h"
#include "TexturedObject.h"


CBackgroundMover::CBackgroundMover()
{
}


CBackgroundMover::~CBackgroundMover()
{

}

void CBackgroundMover::Update(float _deltaTime)
{
}

void CBackgroundMover::Render()
{
	for (CTexturedObject* obj : m_backgrounds)
	{
		obj->Render();
	}
}

void CBackgroundMover::AddObject(CTexturedObject * _object)
{
}
