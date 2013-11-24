#include "UIStaticButton.h"

#include "../../Components/Graphics/SpriteComponent.h"

namespace star
{
	UIStaticButton::UIStaticButton(
		const tstring & name,
		const tstring & file,
		uint32 widthSegements,
		uint32 heightSegements
		)
		: UIUserElement(name)
		, m_pButtonSprite(nullptr)
	{
		m_pButtonSprite = new SpriteComponent(
			file, name + _T("_img"),
			widthSegements,
			heightSegements
			);
		m_pButtonSprite->SetHUDOptionEnabled(true);
		AddComponent(m_pButtonSprite);
	}

	UIStaticButton::~UIStaticButton(void)
	{
		
	}
	
	void UIStaticButton::SetHorizontalAlignment(HorizontalAlignment alignment)
	{
		switch(alignment)
		{
			case HorizontalAlignment::Left:
				GetTransform()->SetCenterX(0);
				break;
			case HorizontalAlignment::Center:
				GetTransform()->SetCenterX(
					float32(m_pButtonSprite->GetWidth()) / 2.0f
					);
				break;
			case HorizontalAlignment::Right:
				GetTransform()->SetCenterX(
					float32(m_pButtonSprite->GetWidth())
					);
				break;
		}
		
		UIElement::SetHorizontalAlignment(alignment);
	}

	void UIStaticButton::SetVerticalAlignment(VerticalAlignment alignment)
	{
		switch(alignment)
		{
			case VerticalAlignment::Bottom:
				GetTransform()->SetCenterY(0);
				break;
			case VerticalAlignment::Center:
				GetTransform()->SetCenterY(
					float32(m_pButtonSprite->GetHeight()) / 2.0f
					);
				break;
			case VerticalAlignment::Top:
				GetTransform()->SetCenterY(
					float32(m_pButtonSprite->GetHeight())
					);
				break;
		}
		
		UIElement::SetVerticalAlignment(alignment);
	}

	void UIStaticButton::SetCurrentHorizontalSegement(uint32 segment)
	{
		m_pButtonSprite->SetCurrentHorizontalSegment(segment);
	}

	void UIStaticButton::SetCurrentVerticalSegement(uint32 segment)
	{
		m_pButtonSprite->SetCurrentVerticalSegment(segment);
	}

	void UIStaticButton::SetCurrentSegement(uint32 segmentX, uint32 segmentY)
	{
		m_pButtonSprite->SetCurrentSegment(segmentX, segmentY);
	}

	vec2 UIStaticButton::GetDimensions() const
	{
		return vec2(
			m_pButtonSprite->GetWidth(),
			m_pButtonSprite->GetHeight()
			);
	}
}
