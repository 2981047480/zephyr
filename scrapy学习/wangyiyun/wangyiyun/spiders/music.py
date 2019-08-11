# -*- coding: utf-8 -*-
import scrapy


class MusicSpider(scrapy.Spider):
    name = 'music'
    allowed_domains = ['music.163.com']
    start_urls = ['https://music.163.com/#/user/songs/rank?id=374072217']

    def parse(self, response):
        url=response.xpath('//*[@id="auto-id-.*?"]/ul/li/div[2]/div/div/span/a/@href').extract()
        print(url)
