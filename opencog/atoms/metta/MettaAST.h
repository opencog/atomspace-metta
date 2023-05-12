/*
 * opencog/atoms/metta/MettaAST.h
 *
 * Copyright (C) 2021, 2022 Linas Vepstas
 * All Rights Reserved
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU Affero General Public License v3 as
 * published by the Free Software Foundation and including the exceptions
 * at http://opencog.org/wiki/Licenses
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU Affero General Public License
 * along with this program; if not, write to:
 * Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */

#ifndef _OPENCOG_METTA_AST_H
#define _OPENCOG_METTA_AST_H

#include <opencog/atoms/foreign/SexprAST.h>
#include <opencog/atoms/metta-types/atom_types.h>

namespace opencog
{
/** \addtogroup grp_atomspace
 *  @{
 */

/// The MettaAST holds MeTTa-like, Lisp-like abstract syntax trees,
/// printed as Lisp-like s-expressions. Quasi-compatible with current
/// experimental MeTTa code.
///
class MettaAST : public SexprAST
{
	void init();
	static std::string prt_metta(const Handle&);

protected:
	virtual Handle next_expr(const std::string&, size_t& l, size_t& r);

public:
	MettaAST(const HandleSeq&&, Type = METTA_AST);
	MettaAST(const HandleSeq&&, const std::string&&);
	MettaAST(const MettaAST&) = delete;
	MettaAST& operator=(const MettaAST&) = delete;

	MettaAST(const std::string&);

	virtual std::string to_string(const std::string& indent) const;
	virtual std::string to_short_string(const std::string& indent) const;

	static Handle factory(const Handle&);
};

LINK_PTR_DECL(MettaAST)
#define createMettaAST CREATE_DECL(MettaAST)

/** @}*/
}

#endif // _OPENCOG_METTA_AST_H
