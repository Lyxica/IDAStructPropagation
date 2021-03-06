#pragma once
#pragma warning(push, 0)        
#include <ida.hpp>
#include <idp.hpp>
#include <expr.hpp>
#include <bytes.hpp>
#include <loader.hpp>
#include <kernwin.hpp>
#include <frame.hpp>
#include <struct.hpp>
#include <name.hpp>
#include <intel.hpp>
#include <cstdio>
#include <set>
#pragma warning(pop)
class struct_processor
{
public:
	struct_processor(ea_t, void (*callback)(ea_t, uint8), uint16 starting_register);

private:
	func_t* func;
	uint processed_lines;
	void (*callback)(ea_t, uint8);
	std::set<ea_t> visited;

	void process(ea_t addr, std::set<uint16>);
	qvector<ea_t> branch_target(insn_t);

};

uint16 did_register_spoil(insn_t, std::set<uint16>);
uint16 check_for_struc_transfer(insn_t, std::set<uint16>);
bool check_for_add(insn_t, std::set<uint16>);