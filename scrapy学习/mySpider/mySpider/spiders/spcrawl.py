# -*- coding: utf-8 -*-
import scrapy
from scrapy.linkextractors import LinkExtractor
from scrapy.spiders import CrawlSpider, Rule


class SpcrawlSpider(CrawlSpider):
    name = 'zuke'
    allowed_domains = ['sh.zu.ke.com']
    start_urls = ['https://sh.zu.ke.com/zufang/SH2298455869585113088.html?nav=0']

    def parse(self, response):
        #print(str(response.body))
        price1=response.xpath('//div[contains(@class,"content__aside fr")]/p/span/text()').extract_first()
        print(price1)
        price2=response.xpath('//div[contains(@class,"content__aside fr")]/p/text()').extract_first()
        print(price2)
        price=price1+price2
        print(price)
        title=response.xpath('//div[contains(@class,"content clear")]/p/text()').extract_first()
        print(title)
        load=response.xpath('//p[contains(@class,"content__aside--tags")]//i/text()').extract()
        print(load)
        id=response.xpath('//div[contains(@class,"content__subtitle")]/i[2]/text()').extract_first()
        print(id)
        time=response.xpath('//div[contains(@class,"content__subtitle")]/text()').extract()
        time=time.pop(1)
        print(time)
        type=response.xpath('//p[@class="content__article__table"]/span[1]/text()').extract_first()
        print(type)
        huxing=response.xpath('//p[@class="content__article__table"]/span[2]/text()').extract_first()
        print(huxing)
        area=response.xpath('//p[@class="content__article__table"]/span[3]/text()').extract_first()
        print(area)
        toward=response.xpath('//p[@class="content__article__table"]/span[4]/text()').extract_first()
        print(toward)
