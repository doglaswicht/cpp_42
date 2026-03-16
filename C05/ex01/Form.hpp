/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dleite-b <dleite-b@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/15 16:45:47 by dleite-b          #+#    #+#             */
/*   Updated: 2026/03/16 16:32:47 by dleite-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP


#include <string>
#include <exception>
#include <ostream>

class Bureaucrat;

class   Form
{
    private:
            const std::string name_;
            bool isSigned_;
            const int gradeToSign_;
            const int gradeToExec_;

    public:
            Form(const std::string& name, int gradeToSign, int gradeToExec);
            Form(const Form& other);
            Form& operator=(const Form& other);
            ~Form();
                
            const std::string& getName()const;
            bool getIsSigned() const;
            int getGradeToSign() const;
            int getGradeToExec()const;
                
            void beSigned(const Bureaucrat& bureaucrat);

    class GradeTooHighException : public std::exception
    {
        public :
                virtual const char* what() const throw();
    };
    class GradeTooLowException : public std::exception
    {
        public :
                virtual const char* what() const throw();
    };
};
std::ostream& operator<<(std::ostream& os, const Form& other);

#endif