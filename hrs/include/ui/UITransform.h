// UITransform.h: interface for the UITransform class.
//
//////////////////////////////////////////////////////////////////////

#ifndef UITRANSFORM_H
#define UITRANSFORM_H

/**@file UITransform.h
* @brief Declares the UITransform
*
* <BR>NAME:UITransform
* 
* <BR>BASE CLASSES:None
* 
* <BR>PURPOSE:To transform form to object and object to form.
*
* <BR>AUTHOR:Smitha Manjunath	
* <BR>
* <BR>$Revision: $12/14/2005
* 
* <BR>$Log:12/14/2005
* 
* <BR>COPYRIGHT NOTICE:
* <BR>Copyright (c) 2005 C++ Capability team at Accenture. All rights reserved.
*/

class AccentureDetails;///<Forward declaration...
class ProjectInfo;///<Forward declaration...
class SkillsInformation;///<Forward declaration...
class SkillCategory;///<Forward declaration...
class EmployeeInfo;///<Forward declaration...


/**@namespace ui
   @brief Declares core UI classes and those that depend on them
 */
namespace ui{

class Form;///<Forward declaration...
class FormElement;///<Forward declaration...


/**@class EmployeeIdGenerator
* @brief  Declaration of UITransform
* <PRE> Class that will transform an object to a form and vice-a-versa
</PRE>
*/

class UITransform  
{
public:

	
 /**@fn UITransform.
  * @brief empty public Constructor.
  * This constructor will not take any argument.
  * @param none
  * @return none
  */
	UITransform();


 /**@fn transformForm2Object.
  * @brief transforms form to object.
  * @param Reference to the object of the class Form and reference to the object of the class EmployeeInfo.
  * @return void.
  */
		void transformForm2Object(Form& form, EmployeeInfo& info );

 /**@fn transformObject2Form.
  * @brief transforms object to form.
  * @param Reference to the object of the class EmployeeInfo and reference to the object of the class Form.
  * @return void.
  */


		void transformObject2Form(EmployeeInfo& info, Form& form);


 /**@fn transformForm2Object.
  * @brief transforms form to object.
  * @param Reference to the object of the class Form and reference to the object of the class AccentureDetails.
  * @return void.
  */
		void transformForm2Object(Form& form, AccentureDetails& accentureDetails);


 /**@fn transformObject2Form.
  * @brief transforms object to form.
  * @param Reference to the object of the class AccentureDetails and reference to the object of the class Form.
  * @return void.
  */

		void transformObject2Form(AccentureDetails& info, Form& form);

/**@fn transformForm2Object.
  * @brief transforms form to object.
  * @param Reference to the object of the class Form and reference to the object of the class ProjectInfo.
  * @return void.
  */
		void transformForm2Object(Form& form, ProjectInfo& pInfo);

/**@fn transformObject2Form.
  * @brief transforms object to form.
  * @param Reference to the object of the class ProjectInfo and reference to the object of the class Form.
  * @return void.
  */

		void transformObject2Form(ProjectInfo& info, Form& form);

/**@fn transformForm2Object.
  * @brief transforms form to object.
  * @param Reference to the object of the class Form and reference to the object of the class SkillsInformation.
  * @return void.
  */
		void transformForm2Object(Form& form, SkillsInformation& skillInfo);

/**@fn transformObject2Form.
  * @brief transforms object to form.
  * @param Reference to the object of the class SkillsInformation and reference to the object of the class Form.
  * @return void.
  */
		void transformObject2Form(SkillsInformation& info, Form& form);

/**@fn transformForm2Object.
  * @brief transforms form to object.
  * @param Reference to the object of the class Form and reference to the object of the class SkillCategory.
  * @return void.
  */
		void transformForm2Object(Form& form, SkillCategory& skillCat);

/**@fn transformObject2Form.
  * @brief transforms object to form.
  * @param Reference to the object of the class SkillCategory and reference to the object of the class Form.
  * @return void.
  */
		void transformObject2Form(SkillCategory& info, Form& form);

};

} //namespace uI


#endif // UITRANSFORM_H
