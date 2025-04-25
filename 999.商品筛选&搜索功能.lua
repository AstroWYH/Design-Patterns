```lua
local ProductFilter = {}

-- Product type enum
ProductFilter.ProductType = {
    None = 0,
    Phone = 1,
    Computer = 2
}

-- Product data structure
ProductFilter.Product = {
    __tostring = function(self)
        local time = os.date("*t", self.m_publishTime)
        return string.format("%d\t%-10s\t%.2f\t%s\t%04d-%02d-%02d %02d:%02d:%02d",
            self.m_id, self.m_name, self.m_price,
            self.m_type == ProductFilter.ProductType.Phone and "Phone" or "Computer",
            time.year, time.month, time.day, time.hour, time.min, time.sec)
    end
}

function ProductFilter.Product:new(id, name, price, publishTime, type)
    local o = {
        m_id = id,
        m_name = name,
        m_price = price,
        m_publishTime = publishTime,
        m_type = type
    }
    setmetatable(o, self)
    self.__index = self
    return o
end

-- Filter criteria
ProductFilter.FilterCriteria = {
    __tostring = function(self)
        return string.format("FilterCriteria(price>%.2f=%s, type=%s=%s)",
            self.m_minPrice, tostring(self.m_filterByPrice),
            self.m_type, tostring(self.m_filterByType))
    end
}

function ProductFilter.FilterCriteria:new()
    local o = {
        m_filterByPrice = false,
        m_minPrice = 0.0,
        m_filterByType = false,
        m_type = ProductFilter.ProductType.None
    }
    setmetatable(o, self)
    self.__index = self
    return o
end

-- Sort criteria
ProductFilter.SortCriteria = {
    __tostring = function(self)
        return string.format("SortCriteria(sortById=%s, sortByLatest=%s)",
            tostring(self.m_sortById), tostring(self.m_sortByLatest))
    end
}

function ProductFilter.SortCriteria:new()
    local o = {
        m_sortById = true,      -- Default sort by ID
        m_sortByLatest = false  -- Sort by latest publish time
    }
    setmetatable(o, self)
    self.__index = self
    return o
end

-- Product manager
ProductFilter.ProductManager = {}

function ProductFilter.ProductManager:new()
    local o = { m_products = {} }
    setmetatable(o, self)
    self.__index = self
    return o
end

-- Add product
function ProductFilter.ProductManager:AddProduct(product)
    table.insert(self.m_products, product)
end

-- Filter products
function ProductFilter.ProductManager:FilterProducts(criteria)
    local result = {}
    for _, p in ipairs(self.m_products) do
        local match = true
        -- Price filter
        if criteria.m_filterByPrice then
            match = match and (p.m_price > criteria.m_minPrice)
        end
        -- Type filter
        if criteria.m_filterByType then
            match = match and (p.m_type == criteria.m_type)
        end
        if match then
            table.insert(result, p)
        end
    end
    return result
end

-- Sort products
function ProductFilter.ProductManager:SortProducts(products, criteria)
    table.sort(products, function(a, b)
        -- Default sort by ID
        if criteria.m_sortById then
            return a.m_id < b.m_id
        end
        -- Sort by latest
        if criteria.m_sortByLatest then
            return a.m_publishTime > b.m_publishTime
        end
        return false
    end)
end

-- Search products
function ProductFilter.ProductManager:SearchProducts(keyword)
    local result = {}
    for _, p in ipairs(self.m_products) do
        if string.find(p.m_name, keyword, 1, true) then
            table.insert(result, p)
        end
    end
    
    -- Default sort by ID
    local defaultSort = ProductFilter.SortCriteria:new()
    defaultSort.m_sortById = true
    self:SortProducts(result, defaultSort)
    
    return result
end

-- Get paginated products
function ProductFilter.ProductManager:GetPaginatedProducts(products, pageNumber, itemsPerPage)
    if pageNumber < 1 or itemsPerPage < 1 then
        return {}
    end

    local startIdx = (pageNumber - 1) * itemsPerPage + 1
    if startIdx > #products then
        return {}
    end

    local endIdx = math.min(startIdx + itemsPerPage - 1, #products)
    local pageProducts = {}
    for i = startIdx, endIdx do
        table.insert(pageProducts, products[i])
    end
    return pageProducts
end

-- Print products
function ProductFilter.ProductManager:PrintProducts(products)
    if #products == 0 then
        print("No matching products found.")
        return
    end

    print("ID\tName\t\tPrice\t\tType\tPublish Time")
    print("------------------------------------------------")
    for _, p in ipairs(products) do
        print(p)
    end
end

-- Get current timestamp
function ProductFilter.GetCurrentTimestamp()
    return os.time()
end

-- Main function
local function main()
    -- Initialize product manager
    local manager = ProductFilter.ProductManager:new()

    -- Add test data
    local now = ProductFilter.GetCurrentTimestamp()
    manager:AddProduct(ProductFilter.Product:new(1, "iPhone 15", 7999.0, now - 24*3600, ProductFilter.ProductType.Phone))
    manager:AddProduct(ProductFilter.Product:new(2, "MacBook Pro", 12999.0, now - 3600, ProductFilter.ProductType.Computer))
    manager:AddProduct(ProductFilter.Product:new(3, "Galaxy S23", 5999.0, now, ProductFilter.ProductType.Phone))
    manager:AddProduct(ProductFilter.Product:new(4, "Surface Pro", 8999.0, now - 2*3600, ProductFilter.ProductType.Computer))
    manager:AddProduct(ProductFilter.Product:new(5, "Pixel 7", 4299.0, now - 48*3600, ProductFilter.ProductType.Phone))
    manager:AddProduct(ProductFilter.Product:new(6, "ThinkPad", 6999.0, now - 10*3600, ProductFilter.ProductType.Computer))
    manager:AddProduct(ProductFilter.Product:new(7, "Redmi K60", 2499.0, now - 8*3600, ProductFilter.ProductType.Phone))
    manager:AddProduct(ProductFilter.Product:new(8, "iMac", 14999.0, now - 12*3600, ProductFilter.ProductType.Computer))

    -- 筛选
    -- Set filter criteria: price > 500 and type = Phone
    local filterCriteria = ProductFilter.FilterCriteria:new()
    filterCriteria.m_filterByPrice = true
    filterCriteria.m_minPrice = 500.0  -- 修改为500以匹配输出描述
    filterCriteria.m_filterByType = true  -- 修改为true以匹配输出描述
    filterCriteria.m_type = ProductFilter.ProductType.Phone
    
    -- Set sort criteria: sort by latest
    local sortCriteria = ProductFilter.SortCriteria:new()
    sortCriteria.m_sortById = false
    sortCriteria.m_sortByLatest = true
    
    -- Apply filters
    local filteredProducts = manager:FilterProducts(filterCriteria)
    -- Apply sorting
    manager:SortProducts(filteredProducts, sortCriteria)
    -- Pagination parameters
    local currentPage = 1  -- 修改为1，因为第2页没有数据
    local itemsPerPage = 7
    -- Get paginated results
    local paginatedProducts = manager:GetPaginatedProducts(filteredProducts, currentPage, itemsPerPage)
    -- Print results
    print(string.format("Filter results (Price > 500, Phones only, sorted by latest, Page %d, %d items per page):", currentPage, itemsPerPage))
    manager:PrintProducts(paginatedProducts)

    -- 搜索（此时忽略筛选）
    print("\n=== Partial Search for 'Mac' ===")
    local partialResults = manager:SearchProducts("Mac")
    for _, p in ipairs(partialResults) do
        print(string.format("%d: %s", p.m_id, p.m_name))
    end
end

-- Run the program
main()
```
