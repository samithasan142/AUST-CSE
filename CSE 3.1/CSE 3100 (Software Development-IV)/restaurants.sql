-- phpMyAdmin SQL Dump
-- version 5.1.1
-- https://www.phpmyadmin.net/
--
-- Host: 127.0.0.1
-- Generation Time: Oct 09, 2021 at 07:54 PM
-- Server version: 10.4.21-MariaDB
-- PHP Version: 8.0.10

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Database: `restaurants`
--

-- --------------------------------------------------------

--
-- Table structure for table `admin_table`
--

CREATE TABLE `admin_table` (
  `id` int(10) UNSIGNED NOT NULL,
  `full_name` varchar(100) NOT NULL,
  `username` varchar(100) NOT NULL,
  `password` varchar(255) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Dumping data for table `admin_table`
--

INSERT INTO `admin_table` (`id`, `full_name`, `username`, `password`) VALUES
(9, 'Tasnimul Hasan', 'hasan12', 'fc3f318fba8b3c1502bece62a27712df'),
(10, 'Samit Hasan', 'samit', '553d5354af8745ed73e0df19ee767a71'),
(12, 'Tamim Iqbal', 'tamim', '70693e458a02b1810e16112aad100f66'),
(13, 'Zahidul', 'zahid', 'c651148415ab2a260e6c506075c12ae3');

-- --------------------------------------------------------

--
-- Table structure for table `category_table`
--

CREATE TABLE `category_table` (
  `id` int(10) UNSIGNED NOT NULL,
  `title` varchar(100) NOT NULL,
  `image_name` varchar(255) NOT NULL,
  `featured` varchar(10) NOT NULL,
  `active` varchar(10) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Dumping data for table `category_table`
--

INSERT INTO `category_table` (`id`, `title`, `image_name`, `featured`, `active`) VALUES
(8, 'চিকেন বিরিয়ানি', 'Food_Category_228.jpg', 'Yes', 'Yes'),
(9, 'মাটন বিরিয়ানি', 'Food_Category_435.png', 'Yes', 'Yes'),
(10, 'গরুর কাচ্চি', 'Food_Category_550.jpg', 'Yes', 'Yes'),
(12, 'হায়দ্রাবাদী বিরিয়ানি', 'Food_Category_687.jpg', 'Yes', 'Yes'),
(13, 'ডেজার্ট ', 'Food_Category_673.jpg', 'Yes', 'Yes'),
(14, 'কোমল পানীয় ', 'Food_Category_761.jpg', 'Yes', 'Yes');

-- --------------------------------------------------------

--
-- Table structure for table `contact_us`
--

CREATE TABLE `contact_us` (
  `id` int(11) NOT NULL,
  `first_name` varchar(50) NOT NULL,
  `last_name` varchar(50) NOT NULL,
  `email` varchar(200) NOT NULL,
  `phone` varchar(11) NOT NULL,
  `message` text NOT NULL,
  `datetime` datetime NOT NULL DEFAULT current_timestamp(),
  `status` int(11) NOT NULL DEFAULT 1
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `contact_us`
--

INSERT INTO `contact_us` (`id`, `first_name`, `last_name`, `email`, `phone`, `message`, `datetime`, `status`) VALUES
(1, 'Mohammad', 'Zahidul Haque', 'jahidprototype2@gmail.com', '+8801670724', 'Greetings from Budapast', '2021-09-09 15:37:07', 1),
(2, 'Samit', 'Hasan', 'samithasan12@gmail.com', '01822108834', 'Nothing', '2021-10-03 19:45:00', 1),
(3, 'Ayman', 'Sadiq', 'ayman@gmail.com', '01700022211', 'Nice ', '2021-10-04 17:17:17', 1);

-- --------------------------------------------------------

--
-- Table structure for table `food_table`
--

CREATE TABLE `food_table` (
  `id` int(10) UNSIGNED NOT NULL,
  `title` varchar(100) NOT NULL,
  `description` text NOT NULL,
  `price` decimal(10,2) NOT NULL,
  `image_name` varchar(255) NOT NULL,
  `category_id` int(10) UNSIGNED NOT NULL,
  `featured` varchar(10) NOT NULL,
  `active` varchar(10) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Dumping data for table `food_table`
--

INSERT INTO `food_table` (`id`, `title`, `description`, `price`, `image_name`, `category_id`, `featured`, `active`) VALUES
(6, 'চিকেন বিরিয়ানি ', 'সুস্বাদু দেশী মুরগির বিরিয়ানি ', '200.00', 'Food-Name-3694.jpeg', 8, 'Yes', 'Yes'),
(7, 'শাহী মাটন বিরিয়ানি', ' পোলার চালের শাহী মাটন বিরিয়ানি', '280.00', 'Food-Name-4955.png', 9, 'Yes', 'Yes'),
(8, 'চিকেন তেহারী ', 'কোয়ার্টার দেশী মুরগির তেহারী ', '150.00', 'Food-Name-1858.jpg', 8, 'Yes', 'Yes'),
(9, 'গরুর কাচ্চি ', 'সুস্বাদু বাসমতি চালের গরুর কাচ্চি ', '200.00', 'Food-Name-7682.jpg', 10, 'Yes', 'Yes'),
(10, 'হায়দ্রাবাদী বীফ বিরিয়ানি ', 'ভারতের ঐতিহ্যবাহী হায়দ্রাবাদী বিরিয়ানি ', '250.00', 'Food-Name-7312.jpg', 12, 'Yes', 'Yes'),
(11, 'গরুর তেহারি ', 'চিনিগুঁড়া পোলার চালের গরুর তেহারি ', '180.00', 'Food-Name-1253.jpg', 10, 'Yes', 'Yes'),
(12, 'মাটন বিরিয়ানি ', 'বাসমতি চালের সুস্বাদু মাটন বিরিয়ানি ', '320.00', 'Food-Name-7197.jpg', 9, 'Yes', 'Yes'),
(13, 'রোজ ফিরনি ', 'সুগন্ধী গোলাপজল যুক্ত ও গুঁড়ো পেস্তা দিয়ে তৈরী মিহি চালের পুডিং', '80.00', 'Food-Name-8301.jpg', 13, 'Yes', 'Yes'),
(14, 'স্ট্রবেরি ফিরনি ', 'স্ট্রবেরি ও  গুঁড়ো পেস্তা দিয়ে তৈরী মিহি চালের পুডিং', '90.00', 'Food-Name-940.jpg', 13, 'Yes', 'Yes'),
(15, 'ম্যাংগো ফিরনি ', 'দেশি আম ও পেস্তা বাদাম দিয়ে তৈরী মিহি চালের পুডিং', '75.00', 'Food-Name-7481.jpg', 13, 'Yes', 'Yes'),
(16, 'আফগানি ফিরনি ', 'স্পেশাল আফগানি ফিরনি ', '80.00', 'Food-Name-8754.jpg', 13, 'Yes', 'Yes'),
(17, 'ইরানিয়ান ফিরনি ', 'স্পেশাল ইরানিয়ান ফিরনি ', '92.00', 'Food-Name-9317.jpg', 13, 'Yes', 'Yes'),
(18, 'হায়দ্রাবাদী চিকেন বিরিয়ানি ', 'দেশি মুরগির শাহী হায়দ্রাবাদি বিরিয়ানি ', '220.00', 'Food-Name-5698.jpg', 12, 'Yes', 'Yes'),
(19, 'হায়দ্রাবাদী মাটন বিরিয়ানি ', 'খাসীর পায়ার তৈরী হায়দ্রাবাদী মাটন বিরিয়ানি ', '325.00', 'Food-Name-4933.png', 12, 'Yes', 'Yes'),
(20, 'কোকাকোলা ', '২৫০ মিঃ লিঃ কোকাকোলা ', '20.00', 'Food-Name-355.jpg', 14, 'Yes', 'Yes'),
(21, 'সেভেন আপ ', '৫০০ মিঃ লিঃ সেভেন আপ ', '35.00', 'Food-Name-7522.png', 14, 'Yes', 'Yes'),
(22, 'মাউন্টেইন ডিউ ', '৫০০ মিঃ লিঃ মাউন্টেইন ডিউ ', '35.00', 'Food-Name-5957.jpg', 14, 'Yes', 'Yes'),
(23, 'ফান্টা ', ' ২৫০ মিঃ লিঃ ফান্টা (ক্যান) ', '20.00', 'Food-Name-7914.jpg', 14, 'Yes', 'Yes'),
(24, 'স্প্রাইট ', '৫০০ মিঃ লিঃ স্প্রাইট ', '35.00', 'Food-Name-1560.jpg', 14, 'Yes', 'Yes'),
(25, 'হায়দ্রাবাদী চিকেন ডাম বিরিয়ানি ', 'স্পেশাল হায়দ্রাবাদী চিকেন ডাম বিরিয়ানি ', '240.00', 'Food-Name-7194.jpg', 12, 'Yes', 'Yes'),
(26, 'মুঘলীয় মাটন বিরিয়ানি ', 'মুঘলীয় স্বাদের মাটন বিরিয়ানি ', '250.00', 'Food-Name-2320.jpg', 9, 'Yes', 'Yes'),
(27, 'কাশ্মীরি চিকেন পোলাও ', 'কাশ্মীরের বিখ্যাত চিকেন পোলাও ', '200.00', 'Food-Name-6734.jpg', 8, 'Yes', 'Yes'),
(28, 'চিকেন ডাম বিরিয়ানি ', 'শাহী চিকেন ডাম বিরিয়ানি ', '180.00', 'Food-Name-4915.jpg', 8, 'Yes', 'Yes'),
(29, 'পাকিস্তানি বিরিয়ানি ', 'করাচির বিখ্যাত ঐতিহ্যবাহী বিরিয়ানি ', '220.00', 'Food-Name-9408.jpg', 8, 'Yes', 'Yes'),
(30, 'স্পেশাল চিকেন বিরিয়ানি (ফ্যামিলি প্যাক)', 'স্পেশাল চিকেন বিরিয়ানি (ফ্যামিলি প্যাক) - ৪ জনের জন্য ', '800.00', 'Food-Name-1313.jpg', 8, 'Yes', 'Yes'),
(31, 'মাটন বিরিয়ানি (ড্রিংস সহ)', 'মাটন বিরিয়ানি - ১ জনের জন্য কোমল পানীয়সহ ', '300.00', 'Food-Name-8807.jpg', 9, 'Yes', 'Yes'),
(32, 'আরাবিয়ান দুম্বা বিরিয়ানি ', 'সৌদি আরবের স্পেশাল দুম্বা বিরিয়ানি ', '270.00', 'Food-Name-3695.jpg', 9, 'Yes', 'Yes'),
(33, 'পাকিস্তানি বীফ বিরিয়ানি ', 'স্পেশাল পাকিস্তানি বীফ বিরিয়ানি ', '220.00', 'Food-Name-9197.jpg', 10, 'Yes', 'Yes'),
(34, 'আসাম বীফ বিরিয়ানি ', 'ভারতের আসামের স্পেশাল বীফ বিরিয়ানি ', '180.00', 'Food-Name-8118.jpg', 10, 'Yes', 'Yes'),
(35, 'পেপসি ', '২৫০ মিঃ লিঃ পেপসি ', '20.00', 'Food-Name-5651.jpg', 14, 'Yes', 'Yes');

-- --------------------------------------------------------

--
-- Table structure for table `order_table`
--

CREATE TABLE `order_table` (
  `id` int(10) UNSIGNED NOT NULL,
  `food` varchar(150) NOT NULL,
  `price` decimal(10,2) NOT NULL,
  `qty` int(11) NOT NULL,
  `total` decimal(10,2) NOT NULL,
  `order_date` datetime NOT NULL,
  `status` varchar(50) NOT NULL,
  `customer_name` varchar(150) NOT NULL,
  `customer_contact` varchar(20) NOT NULL,
  `customer_email` varchar(150) NOT NULL,
  `customer_address` varchar(255) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Dumping data for table `order_table`
--

INSERT INTO `order_table` (`id`, `food`, `price`, `qty`, `total`, `order_date`, `status`, `customer_name`, `customer_contact`, `customer_email`, `customer_address`) VALUES
(5, 'চিকেন বিরিয়ানি ', '200.00', 2, '400.00', '2021-09-28 08:43:04', 'Delivered', 'Samit Hasan', '01900011122', 'samit@gmail.com', 'Khilgaon, Dhaka'),
(6, 'হায়দ্রাবাদী বিরিয়ানি ', '250.00', 5, '1250.00', '2021-09-28 08:45:45', 'Delivered', 'Zahidul Haque', '01700022233', 'zahid@gmail.com', 'Khilgaon, Dhaka'),
(7, 'মাটন বিরিয়ানি ', '320.00', 3, '960.00', '2021-09-28 08:47:31', 'Cancelled', 'Aurnob Aurgho', '01744400022', 'aurnob@gmail.com', 'New Market, Dhaka'),
(8, 'চিকেন তেহারী ', '150.00', 4, '600.00', '2021-09-28 08:49:13', 'On Delivery', 'Ishan Islam', '01433322211', 'ishan@gmail.com', 'Banasree, Dhaka');

--
-- Indexes for dumped tables
--

--
-- Indexes for table `admin_table`
--
ALTER TABLE `admin_table`
  ADD PRIMARY KEY (`id`);

--
-- Indexes for table `category_table`
--
ALTER TABLE `category_table`
  ADD PRIMARY KEY (`id`);

--
-- Indexes for table `contact_us`
--
ALTER TABLE `contact_us`
  ADD PRIMARY KEY (`id`);

--
-- Indexes for table `food_table`
--
ALTER TABLE `food_table`
  ADD PRIMARY KEY (`id`);

--
-- Indexes for table `order_table`
--
ALTER TABLE `order_table`
  ADD PRIMARY KEY (`id`);

--
-- AUTO_INCREMENT for dumped tables
--

--
-- AUTO_INCREMENT for table `admin_table`
--
ALTER TABLE `admin_table`
  MODIFY `id` int(10) UNSIGNED NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=14;

--
-- AUTO_INCREMENT for table `category_table`
--
ALTER TABLE `category_table`
  MODIFY `id` int(10) UNSIGNED NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=15;

--
-- AUTO_INCREMENT for table `contact_us`
--
ALTER TABLE `contact_us`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=5;

--
-- AUTO_INCREMENT for table `food_table`
--
ALTER TABLE `food_table`
  MODIFY `id` int(10) UNSIGNED NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=40;

--
-- AUTO_INCREMENT for table `order_table`
--
ALTER TABLE `order_table`
  MODIFY `id` int(10) UNSIGNED NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=9;
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
