SELECT

    -- Get month (YYYY-MM)
    DATE_FORMAT(trans_date, '%Y-%m') AS month, country,

    -- Total transactions
    COUNT(*) AS trans_count,

    -- Approved transactions
    SUM(CASE WHEN state = 'approved' THEN 1 ELSE 0 END) AS approved_count,

    -- Total transaction amount
    SUM(amount) AS trans_total_amount,

    -- Approved transaction amount
    SUM(CASE WHEN state = 'approved' THEN amount ELSE 0 END) AS approved_total_amount

FROM Transactions

-- Group by month and country
GROUP BY DATE_FORMAT(trans_date, '%Y-%m'), country;