#include <ui/HelperForm.h>
#include <ui/FormElement.h>
#include <common/Validator.h>
#include <ui/Form.h>

namespace ui
{
  std::string HelperForm::getSimpleInput(std::string label)
  {
    ui::FormElement codeElt[] =
      {
    	FormElement(label,        4, 3,30,		   Validator::notNull),

    	FormElement("",	-1, -1, 0,		NULL)
      };

    ui::Form codeForm(codeElt, "");

    if(!(codeForm.handleForm()))	// As simple as this!
      return "";

    std::string res = codeForm.getText(label);

    return res;
  }
}
