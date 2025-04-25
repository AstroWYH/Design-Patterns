```cpp
#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <string>
#include <iomanip>
#define NOMINMAX
#include <windows.h>

namespace ProductFilter
{
	// Product type enum
	enum class ProductType
	{
		None,
		Phone,
		Computer
	};

	// Product data structure
	struct Product
	{
		int m_id;
		std::string m_name;
		double m_price;
		std::chrono::system_clock::time_point m_publishTime;
		ProductType m_type;

		Product(int id, const std::string& name, double price,
			std::chrono::system_clock::time_point time, ProductType type)
			: m_id(id), m_name(name), m_price(price), m_publishTime(time), m_type(type)
		{
		}
	};

	// Filter criteria
	struct FilterCriteria
	{
		bool m_filterByPrice = false;
		double m_minPrice = 0.0;
		bool m_filterByType = false;
		ProductType m_type = ProductType::None;
	};

	// Sort criteria
	struct SortCriteria
	{
		bool m_sortById = true;      // Default sort by ID
		bool m_sortByLatest = false; // Sort by latest publish time
	};

	// Product manager
	class ProductManager
	{
	public:
		// Add product
		void AddProduct(const Product& product)
		{
			m_products.push_back(product);
		}

		// Filter products
		std::vector<Product> FilterProducts(const FilterCriteria& criteria) const
		{
			std::vector<Product> result;
			std::copy_if(
				m_products.begin(),
				m_products.end(),
				std::back_inserter(result),
				[&criteria](const Product& p)
				{
					bool match = true;
					// Price filter
					if (criteria.m_filterByPrice)
					{
						match = match && (p.m_price > criteria.m_minPrice);
					}
					// Type filter
					if (criteria.m_filterByType)
					{
						match = match && (p.m_type == criteria.m_type);
					}
					return match;
				});
			return result;
		}

		// Sort products
		void SortProducts(std::vector<Product>& products, const SortCriteria& criteria) const
		{
			std::sort(
				products.begin(),
				products.end(),
				[&criteria](const Product& a, const Product& b)
				{
					// Default sort by ID
					if (criteria.m_sortById)
					{
						return a.m_id < b.m_id;
					}
					// Sort by latest
					if (criteria.m_sortByLatest)
					{
						return a.m_publishTime > b.m_publishTime;
					}
					return false;
				});
		}

		// Get paginated products
		std::vector<Product> GetPaginatedProducts(
			const std::vector<Product>& products,
			int pageNumber,
			int itemsPerPage) const
		{
			if (pageNumber < 1 || itemsPerPage < 1)
			{
				return {};
			}

			const int startIdx = (pageNumber - 1) * itemsPerPage;
			if (startIdx >= static_cast<int>(products.size()))
			{
				return {};
			}

			const int endIdx = std::min(startIdx + itemsPerPage, static_cast<int>(products.size()));
			return std::vector<Product>(
				products.begin() + startIdx,
				products.begin() + endIdx);
		}

		// Print products
		void PrintProducts(const std::vector<Product>& products) const
		{
			if (products.empty())
			{
				std::cout << "No matching products found.\n";
				return;
			}

			std::cout << "ID\tName\t\tPrice\t\tType\tPublish Time\n";
			std::cout << "------------------------------------------------\n";
			for (const auto& p : products)
			{
				// Convert time point to local time
				auto time = std::chrono::system_clock::to_time_t(p.m_publishTime);
				std::tm tm;
				localtime_s(&tm, &time);

				// Format output
				std::cout << p.m_id << "\t"
					<< std::left << std::setw(10) << p.m_name << "\t"
					<< std::fixed << std::setprecision(2) << p.m_price << "\t"
					<< (p.m_type == ProductType::Phone ? "Phone" : "Computer") << "\t"
					<< std::put_time(&tm, "%Y-%m-%d %H:%M:%S") << "\n";
			}
		}

	private:
		std::vector<Product> m_products;
	};

	// Get current timestamp
	std::chrono::system_clock::time_point GetCurrentTimestamp()
	{
		return std::chrono::system_clock::now();
	}
} // namespace ProductFilter

int main()
{
	using namespace ProductFilter;

	// Initialize product manager
	ProductManager manager;

	// Add test data
	const auto now = GetCurrentTimestamp();
	manager.AddProduct(Product(1, "iPhone 15", 7999.0, now - std::chrono::hours(24), ProductType::Phone));
	manager.AddProduct(Product(2, "MacBook Pro", 12999.0, now - std::chrono::hours(1), ProductType::Computer));
	manager.AddProduct(Product(3, "Galaxy S23", 5999.0, now, ProductType::Phone));
	manager.AddProduct(Product(4, "Surface Pro", 8999.0, now - std::chrono::hours(2), ProductType::Computer));
	manager.AddProduct(Product(5, "Pixel 7", 4299.0, now - std::chrono::hours(48), ProductType::Phone));
	manager.AddProduct(Product(6, "ThinkPad", 6999.0, now - std::chrono::hours(10), ProductType::Computer));
	manager.AddProduct(Product(7, "Redmi K60", 2499.0, now - std::chrono::hours(8), ProductType::Phone));
	manager.AddProduct(Product(8, "iMac", 14999.0, now - std::chrono::hours(12), ProductType::Computer));

	// Set filter criteria: price > 500 and type = Phone
	FilterCriteria filterCriteria;
	filterCriteria.m_filterByPrice = true;
	filterCriteria.m_minPrice = 0.0f;
	filterCriteria.m_filterByType = false;
	filterCriteria.m_type = ProductType::Phone;

	// Set sort criteria: sort by latest
	SortCriteria sortCriteria;
	sortCriteria.m_sortById = false;
	sortCriteria.m_sortByLatest = true;

	// Apply filters
	auto filteredProducts = manager.FilterProducts(filterCriteria);

	// Apply sorting
	manager.SortProducts(filteredProducts, sortCriteria);

	// Pagination parameters
	const int currentPage = 2;
	const int itemsPerPage = 7;

	// Get paginated results
	auto paginatedProducts = manager.GetPaginatedProducts(filteredProducts, currentPage, itemsPerPage);

	// Print results
	std::cout << "Filter results (Price > 500, Phones only, sorted by latest, Page "
		<< currentPage << ", " << itemsPerPage << " items per page):\n";
	manager.PrintProducts(paginatedProducts);

	return 0;
}
```
