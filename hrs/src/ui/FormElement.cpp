#include <ui/FormElement.h>

namespace ui
{
FormElement::FormElement(std::string label, int y, int x, int length, pFunc func, std::string desc, bool canBeNull):

						m_label(label),
						m_value(""),
						m_x(x),
						m_y(y),
						m_maxLength(length),
						m_readonly(false),
						m_validationFunc(func),
                        m_desc(desc),
                        m_canBeNull(canBeNull)
{
}


}
