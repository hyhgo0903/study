#include "stdafx.h"
#include "playGround.h"

playGround::playGround()
{
}


playGround::~playGround()
{
}

//�ʱ�ȭ �Լ�
HRESULT playGround::init()
{
	gameNode::init(true);

	ImageManager::GetInstance()->AddImage("TestObject", L"TrapObject.png");
	ImageManager::GetInstance()->AddFrameImage("TestFrameObject",
		L"Bomb.png", 3, 1);

	return S_OK;
}

//�޸� ����
void playGround::release()
{

}

//����
void playGround::update()
{
	gameNode::update();

}

//�׸��� ����
void playGround::render()
{	
	//����� �ʱ�ȭ
	D2DRenderer::GetInstance()->BeginRender(D2D1::ColorF::Black);
	{
		
		FloatRect rect;
		rect = RectMakePivot(Vector2(WINSIZEX / 2, WINSIZEY / 2),
			Vector2(50, 50), Pivot::Center);
		
		D2DRenderer::GetInstance()->DrawRectangle
		(
			rect,
			D2DRenderer::DefaultBrush::Red,
			1.f
		);
		
		D2DRenderer::GetInstance()->DrawEllipse
		(
			Vector2(WINSIZEX / 2, WINSIZEY / 2), 
			50, 
			D2DRenderer::DefaultBrush::Red,
			1.f
		);
		
		
		//Image* image = ImageManager::GetInstance()->FindImage("TestObject");
		//
		//image->SetAngle(30.f);
		////���Ĵ� 0~1������ ������ 0�� �Ⱥ��̴°Ű� 1�� ���������� ����
		//image->SetAlpha(0.5f);
		////image->SetSize(Vector2(100, 100));
		//image->Render(Vector2(WINSIZEX / 2, WINSIZEY / 2));
		
		Image* frameImage = ImageManager::GetInstance()->FindImage("TestFrameObject");
		
		frameImage->SetAlpha(0.3f);
		frameImage->FrameRender(Vector2(WINSIZEX / 2, WINSIZEY / 2), 0, 0);
	}
	//����ۿ� �׸� ������� ȭ�鿡 �ѷ���~
	D2DRenderer::GetInstance()->EndRender();
}