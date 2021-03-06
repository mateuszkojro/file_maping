#pragma once

#include "huge_ptr.h"

namespace mk {
	template <class Tp>
	struct Allocator {


		Allocator() = default;

		template <class T>
		Allocator(const Allocator<T>&) {}

		static huge_ptr<Tp> allocate(size_t n)
		{
			
			n *= sizeof(Tp);
			return huge_ptr<Tp>::allocate_huge(n);
		}

		static void deallocate(huge_ptr<Tp>& p, size_t n)
		{
			p.free();
		}

		static void deallocate(huge_ptr<Tp>& p)
		{
			p.free();
		}


	};
	template <class T, class U>
	bool operator==(const Allocator<T>&, const Allocator<U>&) { return true; }
	template <class T, class U>
	bool operator!=(const Allocator<T>&, const Allocator<U>&) { return false; }


}

