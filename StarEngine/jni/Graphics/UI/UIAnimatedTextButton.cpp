#include "UIAnimatedTextButton.h"
#include "UITextField.h"

namespace star
{
	UIAnimatedTextButton::UIAnimatedTextButton(
		const tstring & name,
		const tstring & file,
		const tstring & spritesheet,
		const tstring & text,
		const tstring & fontName,
		const Color & color
		)
		: UIAnimatedButton(name, file, spritesheet)
		, m_pTextField(nullptr)
	{
		for(uint8 i = 0 ; i < 4 ; ++i)
		{
			m_StateColors[i] = color;
		}

		m_pTextField = new UITextField(
			name + _T("_txt"),
			text,
			fontName,
			color
			);

		AddElement(m_pTextField);
	}

	UIAnimatedTextButton::UIAnimatedTextButton(
		const tstring & name,
		const tstring & file,
		const tstring & spritesheet,
		const tstring & text,
		const tstring & fontName,
		const tstring & fontPath,
		float32 fontSize,
		const Color & color
		)
		: UIAnimatedButton(name, file, spritesheet)
		, m_pTextField(nullptr)
	{
		for(uint8 i = 0 ; i < 4 ; ++i)
		{
			m_StateColors[i] = color;
		}

		m_pTextField = new UITextField(
			name + _T("_txt"),
			text,
			fontName,
			fontPath,
			fontSize,
			color
			);

		AddElement(m_pTextField);
	}

	UIAnimatedTextButton::~UIAnimatedTextButton()
	{

	}

	void UIAnimatedTextButton::SetIdleColor(const Color & color)
	{
		m_StateColors[uint8(ElementStates::IDLE)] = color;
	}

	void UIAnimatedTextButton::SetHoverColor(const Color & color)
	{
		m_StateColors[uint8(ElementStates::HOVER)] = color;
	}

	void UIAnimatedTextButton::SetClickColor(const Color & color)
	{
		m_StateColors[uint8(ElementStates::CLICK)] = color;
	}

	void UIAnimatedTextButton::SetDisableColor(const Color & color)
	{
		m_StateColors[3] = color;
	}

	void UIAnimatedTextButton::SetText(const tstring & text)
	{
		m_pTextField->SetText(text);
	}

	const tstring & UIAnimatedTextButton::GetText() const
	{
		return m_pTextField->GetText();
	}

	void UIAnimatedTextButton::TranslateText(const vec2& translation)
	{
		m_pTextField->Translate(translation);
	}

	void UIAnimatedTextButton::TranslateText(float32 x, float32 y)
	{
		m_pTextField->Translate(x, y);
	}

	void UIAnimatedTextButton::TranslateTextX(float32 x)
	{
		m_pTextField->TranslateX(x);
	}

	void UIAnimatedTextButton::TranslateTextY(float32 y)
	{
		m_pTextField->TranslateY(y);
	}

	void UIAnimatedTextButton::SetHorizontalAlignmentText(HorizontalAlignment alignment)
	{
		m_pTextField->SetHorizontalAlignment(alignment);
	}

	void UIAnimatedTextButton::SetVerticalAlignmentText(VerticalAlignment alignment)
	{
		m_pTextField->SetVerticalAlignment(alignment);
	}
	
	void UIAnimatedTextButton::SetTextCentered()
	{
		m_pTextField->SetAlignmentCentered();
	}
	
	void UIAnimatedTextButton::GoIdle()
	{
		m_pTextField->SetColor(m_StateColors[int8(m_ElementState)]);
		UIAnimatedButton::GoIdle();
	}

#ifdef DESKTOP
	void UIAnimatedTextButton::GoHover()
	{
		m_pTextField->SetColor(m_StateColors[int8(m_ElementState)]);
		UIAnimatedButton::GoHover();
	}
#endif

	void UIAnimatedTextButton::GoClick()
	{
		m_pTextField->SetColor(m_StateColors[int8(m_ElementState)]);
		UIAnimatedButton::GoClick();
	}

	void UIAnimatedTextButton::GoFreeze()
	{
		m_pTextField->SetColor(m_StateColors[DISABLE_STATE_ID]);
		UIAnimatedButton::GoFreeze();
	}
}
